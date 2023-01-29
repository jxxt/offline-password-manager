#include <iostream>
#include <fstream>
#include "save.cpp"

using namespace std;

class View
{
public:
    char choice1_;
    char choice2_;

    string account_;
    string password_;

    string username_;

    int password_length_;

    void account__input()
    {
        username_ = user_name;
        cout << "\nenter account name: ";
        cin >> account_;
    }

    void retrieve()
    {
        password_ = "";
        ifstream password_view;
        password_view.open(username_ + "_pass_" + account_ + ".txt");
        password_view >> password_;
        password_view.close();

        password_length_ = password_.length();
    }

    void password_decrypt()
    {
        for (int i = 0; i < password_length_; i = i + 2)
        {
            password_[i] = password_[i] - 5;
        }
        for (int i = 1; i < password_length_; i = i + 2)
        {
            password_[i] = password_[i] + 5;
        }
    }

    void viewing()
    {
        account__input();
        retrieve();
        password_decrypt();

        if (password_ == "")
        {
            cout << "\nThe account doesn't exists!";

            cout << "\n\nDo you want to try again?";
            cout << "\nenter 'y' for yes and 'n' for no and exit: ";
            cin >> choice1_;

            if (choice1_ == 'y')
            {
                viewing();
            }

            else
            {
                exit;
            }
        }

        else
        {
            cout << "\nPassword is: " << password_;

            cout << "\n\ndo you want to view another password?";
            cout << "\nenter 'y' for yes and 'n' for no and exit: ";
            cin >> choice2_;

            if (choice2_ == 'y')
            {
                viewing();
            }

            else
            {
                exit;
            }
        }
    }
};