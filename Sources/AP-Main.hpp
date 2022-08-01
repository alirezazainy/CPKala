#include <iostream>
#include <conio.h>
#include <strings.h>
#include <windows.h>

using namespace std;

int uid = 0;
void Main_Menu();
int Register();
bool Validation();
void Login();
void Store_Menu();
void Show_list(string cat);
void Set();
void List();
void Admin_Delete(int i);
void Off(int i);
#include "AP-User.hpp"
#include "AP-Commodity.hpp"
Admin admin;
User user[256];
Commodity com[256];
#include "AP-Log.hpp"

int main()
{
    Main_Menu();
    system("cls");
    cout << "Coded By Alireza Zainy\nCoded With Galb :)";
}

void Main_Menu()
{
    system("cls");
    cout << "(: !________Welcome To CPKala________! :)" << endl;
    int stc;
    int _reg;
    int _log;
    cout << "Please Choose Action From Menu: " << endl;
    cout << "1.Register\n2.Login\n3.Store\n4.Exit\n";
    cin >> stc;
    switch (stc)
    {
    case 1:
        uid = Register();
        user[uid].Reg();
        Main_Menu();
        break;
    case 2:
        Login();
        Main_Menu();
        break;
    case 3:
        Store_Menu();
        Main_Menu();
        break;
    case 4:
        break;
    default:
        system("cls");
        cerr << "Your choose isn't in this list !" << endl;
        Main_Menu();
        break;
    }
}

