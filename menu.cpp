#include <iostream>
// #include "save.cpp"
#include "view.cpp"

using namespace std;

class Menu : public Save, public View
{
public:
    int choice;

    void options()
    {
        cout << "\n\nwhat do you want to perform?";
        cout << "\n1. save new password";
        cout << "\n2. view saved password";
        // cout << "\n3. suggest random password";
        cout << "\n3. exit";
    }

    void select()
    {
        cout << "\n\nenter your choice: ";
        cin >> choice;
    }

    void work()
    {
        while (true)
        {
            options();
            select();

            if (choice == 1)
            {
                account_input();
                saving();
            }
            else if (choice == 2)
            {
                viewing();
            }
            else if (choice == 3)
            {
                cout << "\nTHANK YOU FOR USING PASSWORD MANAGER!\n\n";
                break;
            }
        }
    }
};

// int main()
// {
//     Menu m;
//     m.work();
// }