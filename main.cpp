#include <iostream>
#include "title.cpp"
// #include "security.cpp"
#include "menu.cpp"

using namespace std;

int main()
{
    Title t;
    t.print();

    decryption d;
    d.print();
    d.option();

    Menu m;
    m.work();

    return 0;
}