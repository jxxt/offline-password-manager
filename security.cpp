#include <iostream>
#include <fstream>
#include <cstring>
#include "login.cpp"

using namespace std;

class encryption : public accout_access
{
public:
    string enc_acc_pw;

    int len;

    void open_file()
    {
        ifstream enc_pw_open;
        enc_pw_open.open(user_name + "_pw" + ".txt");
        enc_pw_open >> enc_acc_pw;
        enc_pw_open.close();

        len = enc_acc_pw.length();
    }

    void encrypt()
    {
        for (int i = 0; i < len; i = i + 2)
        {
            enc_acc_pw[i] = enc_acc_pw[i] + 5;
        }
        for (int i = 1; i < len; i = i + 2)
        {
            enc_acc_pw[i] = enc_acc_pw[i] - 5;
        }
    }

    void close_file()
    {
        ofstream enc_pw_close;
        enc_pw_close.open(user_name + "_pw" + ".txt");
        enc_pw_close << enc_acc_pw;
        enc_pw_close.close();
    }
};

class decryption : public encryption
{
public:
    string dec_acc_pw;

    int len;

    void open_file_dc()
    {
        ifstream dec_pw;
        dec_pw.open(user_name + "_pw" + ".txt");
        dec_pw >> dec_acc_pw;
        dec_pw.close();

        len = dec_acc_pw.length();
    }

    void decrypt()
    {
        for (int i = 0; i < len; i = i + 2)
        {
            dec_acc_pw[i] = dec_acc_pw[i] - 5;
        }
        for (int i = 1; i < len; i = i + 2)
        {
            dec_acc_pw[i] = dec_acc_pw[i] + 5;
        }
    }

    void option()
    {
        while (true)
        {

            cin >> choice1;

            if (choice1 == 1)
            {
                login();
                break;
            }

            else if (choice1 == 2)
            {
                new_username();
                new_password();
                break;
            }

            else
            {
                cout << "\nenter a valid choice: ";
            }
        }
    }

    void new_password()
    {
        cout << "set a new password: ";
        cin >> pw;
        ofstream password_save;
        password_save.open(user_name + "_pw" + ".txt");
        password_save << pw << endl;
        password_save.close();
        open_file();
        encrypt();
        close_file();
        cout << "\naccount created successfully!";
        cout << "\n\ndo you want to login to your account?";
        cout << "\nenter 'y' for yes and 'n' for no and exit: ";
        cin >> choice4;
        if (choice4 == 'y')
        {
            login();
        }
    }

    void login()
    {
        username();
        username_verify();
    }

    void username_verify()
    {
        ifstream user_name_check;
        user_name_check.open(user_name + ".txt");
        user_name_check >> user_name_array;
        user_name_check.close();

        if (user_name_array == user_name)
        {
            password();
            password_check();
        }

        else
        {
            cout << "usernmae doesn't exists. do you want to create a new accout?\n";
            cout << "enter 'y' for yes and 'n' for no and try again: ";
            cin >> choice2;
            if (choice2 == 'y')
            {
                new_username();
                new_password();
            }
            else if (choice2 == 'n')
            {
                login();
            }
        }
    }

    void password_check()
    {
        open_file_dc();
        decrypt();
        ifstream password_check;
        password_check.open(user_name + "_pw" + ".txt");
        password_check >> pw_array;
        password_check.close();

        if (pw == dec_acc_pw)
        {
            cout << "\n\nHELLO " << user_name << ", THIS IS YOUR PASSWORD MANAGER";
        }

        else
        {
            cout << "the entered password is wrong!";
            cout << "\n\ndo you want to try again?";
            cout << "\nenter 'y' for yes and 'n' for no and exit: ";
            cin >> choice3;
            if (choice3 == 'y')
            {
                username_verify();
            }
        }
    }
};

// int main()
// {
//     decryption d;
//     d.print();
//     d.option();

//     cout << user_name;
// }