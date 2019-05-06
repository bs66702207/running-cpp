#include <iostream>

using namespace std;

int main()
{
    char ch;

    cout << "Enter a character: " << endl;
    cin >> ch;
    cout << "Hola! ";
    cout << "Thank you for the " << ch << " character." << endl;//会打印字符，而不是数字
    cout << "Thank you for the " << (int)ch << " character." << endl;
    return 0;

}
