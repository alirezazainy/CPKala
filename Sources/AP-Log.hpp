#include <iostream>
#include <conio.h>
#include <strings.h>
#include <windows.h>



using namespace std;

void Login()
{
    int i;
    int stc;
    string _un = "\0";
    string _pass = "\0";
    cout << "Did you register?\n1.Yes            2.No" << endl;
    cin >> stc;
    system("cls");
    if(stc == 1)
    {
        cout << "Please Enter your Username:" << endl;
        cin >> _un;
        cout << "Please Enter your Password:" << endl;
        cin >> _pass;
        if (_un == "Admin" && _pass == "Admin@123456")
        {
            admin.Login();
        }
        else
        {
            for ( i = 0; i <= 255; i++)
            {
                if (user[i].userName == _un && user[i].passWord == _pass)
                {
                    system("cls");
                    cout << "Welcome --> " << user[i].userName << endl;
                    user[i].logged_In = true;
                    break;
                }
                else
                {
                system("cls");
                cerr << "Username or Password are incorrect" << endl;
                Login();
                }
            }
            user[i].User_Menu();
            uid = i;
        }
    }
    else
    {
        uid = Register();
        user[uid].Reg();
        Login();
    }
}
int Register()
{
    bool _reg = true;
    int i;
    for (i = 0; i <= 255; i++)
    {
        if (_reg != user[i].Registered)
        {
            break;
        }
    }
    return i;
}
bool Validation()
{
    bool _dv = false;
    for (int i = 0; i <= Register(); i++)
    {
        if (user[i].userName == user[i-1].userName)
        {
            _dv = true;
            break;
        }
    }
    return _dv;
}
void Store_Menu()
{
    system("cls");
    int stc;   
    cout << "Please choose a category or search a commodity:" << endl;
    cout << "1.Digital\n2.SuperMarket\n3.Clothes\n4.Children\n5.Tools\n6.Back to main menu\n";
    cin >> stc;
    switch (stc)
    {
    case 1:
        Show_list("Digital");
        Store_Menu();
        break;
    case 2:
        Show_list("SuperMarket");
        Store_Menu();
        break;
    case 3:
        Show_list("Clothes");
        Store_Menu();        
        break;
    case 4:
        Show_list("Children");
        Store_Menu();    
        break;
    case 5:
        Show_list("Tools");
        Store_Menu();        
        break;
    case 6:   
        system("cls");     
        break;
    default:
        system("cls");
        cerr << "Your choose isn't in this list !" << endl;
        Store_Menu();
        break;
    }
}

void Show_list(string cat)
{
    int _ch;
    int _stc;
    cout << "---------------" << cat << "---------------" << endl;
    for (int l = 0; l <= 255; l++)
    {
        if (com[l].setted == true)
        {
            if (cat == com[l].Category)
            {
                if (com[l].AV != 0)
                {
                    cout << l + 1 << ". " << com[l].comName << endl;
                }
            }
        }
    }
   
    cout << "Choose a Commodity(Press 0 to back to menu):" << endl;
    cin >> _ch;
    if(_ch == 0)
    {
        
    }
    else
    {
        _ch -= 1;
        cout << "<<" << com[_ch].comName << ">>" << endl;
        if (com[_ch].Off != 0)
        {
            cout << "Price : " << com[_ch].iPrice << "with " << com[_ch].Off << "% off -------->" << com[_ch].fPrice << endl; 
        }
        else
        {
            cout << "Price : " << com[_ch].fPrice << endl; 
        }
        cout << "Do you like to buy?\n1.Yes         2.No " << endl;
        cin >> _stc;
        if (user[uid].logged_In == true)
        {
            if (_stc == 1)
            {
                int num = com[_ch].Sell();
                if (user[uid].supply >= (com[_ch].fPrice * num))
                {
                    user[uid].supply -= (com[_ch].fPrice * num);
                    cout << "___________________Receipt___________________\n" << com[_ch].comName << "\nNumber: " << num << "\nFor:" << user[uid].userName << "\nCash :" << (com[_ch].fPrice * num) << endl; 
                    cout << "Please press any key+enter to restore to store" << endl;
                    cin >> num;
                }
                else 
                {
                    system("cls");
                    cout << "You don't have supply in your wallet" << endl;
                    user[uid].cash();
                    Show_list(cat);
                }
            
            }
        }
        else 
        {
            system("cls");
            cout << "You are not logged in !!" << endl;
            Login();
        }
    }
    
}

void Set()
{
    int i;
    for (i = 0; i <= 255; i++)
    {
        if(com[i].setted == false)
        {
            break;
        }
    }
    com[i].set_Com();
}
    
void List()
{
    int i;
    for (i = 0; i <= 255; i++)
    {
        if (com[i].setted == true)
        {
            cout << i + 1 << " . " << com[i].comName << endl;
            cout << com[i].Category << endl;
        }
    }
}
void Admin_Delete(int i)
{
    com[i].Delete();
}

void Off(int i)
{
    com[i].set_Off();
}