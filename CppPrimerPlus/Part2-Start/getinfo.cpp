#include <iostream>

using namespace std;

int main() {

    int carrots;

    cout << "How many carrots do you have?" << endl;
    cin >> carrots; //C++ input 12
    cout << "Here are two more. ";
    carrots = carrots + 2;
    cin.get();//recv Enter
    cin.get();//recv Enter twice
    cout << "Now you have " << carrots << " carrots." << endl;
    return 0;
}
