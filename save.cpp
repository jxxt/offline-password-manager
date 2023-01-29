#include <iostream>
#include <fstream>
#include "security.cpp"

using namespace std;

class Save
{
public:
    char choice;

    string account;
    string password;

    string username;

    int password_length;

    int UpperChar;
    int LowerChar;
    int SpecialChar;
    int NumChar;

    void account_input()
    {
        username = user_name;
        cout << "\nenter account name: ";
        cin >> account;
    }

    void password_input()
    {
        cout << "enter password: ";
        cin >> password;

        password_length = password.length();
    }

    void password_encrypt()
    {
        for (int i = 0; i < password_length; i = i + 2)
        {
            password[i] = password[i] + 5;
        }
        for (int i = 1; i < password_length; i = i + 2)
        {
            password[i] = password[i] - 5;
        }
    }

    void strength_checker()
    {
        UpperChar = 0;
        LowerChar = 0;
        SpecialChar = 0;
        NumChar = 0;

        for (int i = 0; i < password_length; i++)
        {
            if (password[i] >= 33 && password[i] <= 47 || password[i] >= 58 && password[i] <= 64 || password[i] >= 91 && password[i] <= 96)
            {
                SpecialChar++;
            }
            if (password[i] >= 48 && password[i] <= 57)
            {
                NumChar++;
            }
            if (password[i] >= 65 && password[i] <= 90)
            {
                UpperChar++;
            }
            if (password[i] >= 97 && password[i] <= 122)
            {
                LowerChar++;
            }
        }
    }

    void strength()
    {
        if (SpecialChar == 1)
        {
            cout << "\n\nStrength of Password: Weak";
        }

        else if (SpecialChar > 1 && SpecialChar <= 3)
        {
            cout << "\n\nStrength of Password: Moderate";
        }

        else if (SpecialChar > 3)
        {
            cout << "\n\nStrength of Password: Strong";
        }
    }

    void saving()
    {
        password_input();

        if (password_length >= 8)
        {
            strength_checker();

            if (SpecialChar >= 1 && NumChar >= 1 && UpperChar >= 1 && LowerChar >= 1)
            {
                password_encrypt();
                ofstream password_save;
                password_save.open(username + "_pass_" + account + ".txt");
                password_save << password;
                password_save.close();

                cout << "\n\nPassword Saved!";

                strength();

                cout << "\n\ndo you want to save another password?";
                cout << "\nenter 'y' for yes and 'n' for no and exit: ";
                cin >> choice;

                if (choice == 'y')
                {
                    account_input();
                    saving();
                }

                else
                {
                    exit;
                }
            }

            else
            {
                if (SpecialChar == 0)
                {
                    cout << "the password doesn't contain any 'special character', try entering 1 or more 'special character(s)' to your password and try again\n\n";
                    saving();
                }

                else if (NumChar == 0)
                {
                    cout << "the password doesn't contain any 'number', try entering 1 or more 'number(s)' to your password and try again\n\n";
                    saving();
                }
                else if (UpperChar == 0)
                {
                    cout << "the password doesn't contain any 'upper character', try entering 1 or more 'upper character(s)' to your password and try again\n\n";
                    saving();
                }

                else if (LowerChar == 0)
                {
                    cout << "the password doesn't contain any 'lower  character', try entering 1 or more 'lower character(s)' to your password and try again\n\n";
                    saving();
                }
            }
        }

        else
        {
            cout << "enter password is too short, please enter a password with 8 or more characters and try again\n\n";
            saving();
        }
    }
};