#include <iostream>

using namespace std;

int main()
{
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Monsieur cuts a striking figure!" << endl;
    cout << "chest = " << chest << " (decimal for 42)" << endl;

    cout << hex;
    cout << "waist = 0x" << waist << " (hexadecimal for 42)" << endl;

    cout << oct;
    cout << "inseam = 0" << inseam << " (octal for 42)" << endl;;

    return 0;
}
