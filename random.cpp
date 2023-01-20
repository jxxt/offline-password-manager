#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
#include <algorithm>
#include "login.cpp"
#include <unistd.h>
#include <cstdlib>

using namespace std;

class Random
{
public:
    int index = 0;
    // char random_password[12];
    string random_password;
    string account;
    string username;

    char choice;

    int random()
    {
        srand(time(NULL));
        for (int i = 0; i < 3; i++)
        {
            random_password[i] = '1' + rand() % 9;
        }
        for (int i = 3; i < 6; i++)
        {
            random_password[i] = 'A' + rand() % 26;
        }
        for (int i = 6; i < 9; i++)
        {
            random_password[i] = '!' + rand() % 14;
        }
        for (int i = 9; i < 12; i++)
        {
            random_password[i] = 'a' + rand() % 26;
        }

        // random_shuffle(random_password, random_password + 12);
    }

    int encryption()
    {
        for (int i = 0; i < 12; i = i + 2)
        {
            random_password[i] = random_password[i] + 5;
        }
        for (int i = 1; i < 12; i = i + 2)
        {
            random_password[i] = random_password[i] - 5;
        }
    }

    int random__password()
    {
        username = user_name;

        random();

        cout << "\nrandom password genrated is: ";
        for (int i = 0; i < 12; i++)
        {
            cout << random_password[i];
        }

        cout << "\n\ndo you want to save this password?";
        cout << "\ntype 'y' for yes and 'n' for no: ";
        cin >> choice;

        if (choice == 'y')
        {
            cout << "\nenter which account's password it is: ";
            cin >> account;

            // encryption();

            ofstream random_pass;
            random_pass.open(username + "_pass_" + account + ".txt");
            random_pass << random_password;

            cout << "\nPassword Saved!";
        }

        else if (choice == 'n')
        {
            exit;
        }

        else
        {
            cout << "\nenter a valid input!";
            ;
        }
    }
};

int main()
{
    Random r;
    r.random__password();
    return 0;
}