#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

string user_name;

class accout_access
{
public:
    int choice1;

    char choice2;
    char choice3;
    char choice4;

    // string user_name;
    string pw;
    string user_name_array;
    string pw_array;

    void print()
    {
        cout << "\nwhat do you want to do?\n";
        cout << "1. log in to existing account\n";
        cout << "2. sign up to new account\n";
        cout << "\nenter your choice: ";
    }

    void username()
    {
        cout << "\nusername: ";
        cin >> user_name;
    }

    void password()
    {
        cout << "password: ";
        cin >> pw;
    }

    void new_username()
    {
        cout << "\nenter new username: ";
        cin >> user_name;
        ofstream username_save(user_name + ".txt");
        username_save << user_name << endl;
    }
};