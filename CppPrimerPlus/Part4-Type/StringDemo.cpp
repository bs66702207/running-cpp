#include <iostream>
#include <string>
#include <cstring>

int main()
{
    using namespace std;
	string s;
    string s1 = "aaa";
    string s2 = "bbb";
    string s3 = "ccc";

    cout << &s << ": " << s << endl;
    s = s1 + s2;
    cout << &s << ": " << s << endl;
    s = s3;
    cout << &s << ": " << s << endl;

    return 0;
}

