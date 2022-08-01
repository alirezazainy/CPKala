#include <iostream>
#include <conio.h>
#include <strings.h>
#include <windows.h>

using namespace std;

class User
{
    friend void Show_list(string cat);
    friend void Login();
    friend int Register();
    friend bool Validation();
    friend void Show_list();
private:
    string userName;
    string passWord;
    long unsigned int supply;
    bool logged_In;
    bool Registered;

public:
    User()
    {
        Registered = false;
        logged_In = false;
        supply = 0;
    }
    void Reg()
    {
        string _un = "\0";
        string _pass = "\0";
        cout << "Please enter Username you want to set:" << endl;
        cin >> _un;
        cout << "Please enter Password you want to set:" << endl;
        cin >> _pass;
        if (Validation() == false)
        {
            userName = _un;
            passWord = _pass;
            logged_In = false;
            Registered = true;
        }
        else
        {
            system("cls");
            cerr << "This username Already available on site\nPlease set another" << endl;
            Reg();
        }
    }
    void Change_Password()
    {
        if (logged_In == 1)
        {
            string _pass;
            cout << "Please enter your last Password:" << endl;
            cin >> _pass;
            if (passWord == _pass)
            {
                cout << "Please enter new Password:" << endl;
                cin >> _pass;
                passWord = _pass;
            }
            else
            {
                cerr << "Your Password isn't correct !" << endl;
                Change_Password();
            }
        }
        else
        {
            cerr << "You didn't login !" << endl;
            Login();
        }
    }
    void cash()
    {
        int i;
        string _cn;
        string _pass;
        long unsigned int _sup;
        cout << "How much you want to cost(in dollars):" << endl;
        cin >> _sup;
        cout << "Please enter your 16-digits card Num.:" << endl;
        cin >> _cn;
        cout << "Please enter your second-pass:" << endl;
        cin >> _pass;
        supply += _sup;
        cout << "_____________ Pay Result _____________\nFrom :" << userName <<"\n From card :" << _cn << "\nDone" << endl;
        cout << "Press any key+enter to continue" << endl;
        cin >> _pass;
    }

    void User_Menu()
    {
        system("cls");
        int stc;
        cout << ">>>>>==============User Menu==============>>>>>" << endl;
        cout << "Your Salary:" << supply << endl;
        cout << "1.Store\n2.Increase credit\n3.Change Password\n4.Logout\n";
        cin >> stc;
        switch (stc)
        {
        case 1:
            Store_Menu();
            User_Menu();
            break;
        case 2:
            cash();
            User_Menu();
            break;
        case 3:
            Change_Password();
            User_Menu();
            break;
        case 4:
            Logout();
            break;
        default:
            system("cls");
            cerr << "Your choose isn't in this list !" << endl;
            User_Menu();
            break;
        }
    }
    void Logout()
    {
        system("cls");
        cout << "Good luk!!!!!" << endl;
        logged_In = false;
        uid = 0;
    }
};

class Admin
{
private:
    string userName;
    string passWord;
    bool admin_Logged_in;

public:
    Admin()
    {
        userName = "Admin";
        passWord = "Admin@123456";
        admin_Logged_in = false;
    }
    void Login()
    {
        admin_Logged_in = true;
        Admin_Menu();
    }
    void Admin_Menu()
    {
        system("cls");
        int i;
        int stc;
        cout << "Hello Bro !!!!\nWhat do you want to do:\n1.Set Commodity\n2.Delete Commodity\n3.Commodity List\n4.set Off\n5.Logout\n";
        cin >> stc; 
        switch (stc)
        {
        case 1:
            Set();
            Admin_Menu();
            break;
        case 2:
            List();
            cout << "Please Select to delete:" << endl;
            cin >> i;
            Admin_Delete(i - 1);
            Admin_Menu();
            break;
        case 3:
            List();
            Admin_Menu();
        case 4:
            List();
            cout << "Please Select to set off:" << endl;
            cin >> i;
            Off(i - 1);
            Admin_Menu();
            break;
        case 5: 
            Logout();
            break;
        default:
            system("cls");
            cerr << "Your choose isn't in this list !" << endl;
            Admin_Menu();
            break;
        }
    }
    void Logout()
    {
        admin_Logged_in = false;
    }
};