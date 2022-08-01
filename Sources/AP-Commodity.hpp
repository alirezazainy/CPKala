#include <iostream>
#include <conio.h>
#include <strings.h>
#include <windows.h>

using namespace std;

class Commodity
{
    friend void Set();
    friend void List();
    friend void Show_list(string cat);
    private:
    string comName;
    float Off;
    long int iPrice;
    long int fPrice;
    long int AV;
    string Category;
    bool setted;
    public:
    Commodity()
    {
        comName = "\0";
        Category = "\0";
        setted = false;
        
    }
    void set_Com()
    {
        string _cn;
        long unsigned int i;
        cout << "Please enter commodity name:" << endl;
        cin >> _cn;
        comName = _cn;
        cout << "Please enter commodity price:" << endl;
        cin >> i;
        iPrice = i;
        cout << "Choose category:\n1.Digital\n2.SuperMarket\n3.Clothes\n4.Children\n5.Tools\n";
        cin >> i;
        switch (i)
        {
        case 1:
            Category = "Digital";
            break;
        case 2:
            Category = "SuperMarket";
            break;
        case 3:
            Category = "Clothes";
            break;
        case 4:
            Category = "Children";
            break;
        case 5:
            Category = "Tools";
            break;       
        default:
            cerr << "Invalid Category!!!!!" << endl;
            set_Com();
            break;
        }
        cout << "Please enter availablity:" << endl;
        cin >> i;
        AV = i;
        cout << "Done!";
        setted = true;
        fPrice = iPrice;
    }
    virtual void set_Off() 
    {
        float i;
        cout << "Please enter Off-percent you want for this commodity(between 10 and 90):" << endl;
        cin >> i;
        if (10 <= i <= 100)
        {
            Off = i;
            fPrice = iPrice - (iPrice*(Off/100));
            system("cls");
            cout << "Off setted!" << endl;
        }
        else 
        {
            system("cls");
            cerr << "This value is invalid!\nbetween 10 and 90\n";
            set_Off();
        }
    }
    int Sell()
    {
        int num;
        string Postcode;
        cout << "Please enter number of " << comName << " you want:" << endl;
        cin >> num;
        AV -= num;
        cout << "Please enter your PostalCode:" << endl;
        cin >> Postcode;
        system("cls");
        cout << "---------Reciept---------\n From :" << comName << "\nPrice of each : " << fPrice << "\nTotal : " << fPrice * num << "\nWill send to your Address";
        cout << "\nDone!!!\nGoodluk!";
        return num;
    }
    void Delete()
    {
        comName = "\0";
        Off = 0;
        iPrice = 0;
        fPrice = 0;
        AV = 0;
        Category = "\0";
        setted = false;
    }
    
};

