#include <iostream>
using namespace std;

int main()
{
    char* str[] = {
        "aiueo",
        "kakikukeko",
        "wawonn",
        "a",
        "i"
    };

    cout << str[0] << endl;
    cout << str[1] << endl;
    cout << str[2] << endl;
    cout << str[3] << endl;
    cout << str[4] << endl;

    cout << "////////// Address ////////// " << endl;
    cout << &str[0] << endl;
    cout << &str[1] << endl;
    cout << &str[2] << endl;
    cout << &str[3] << endl;
    cout << &str[4] << endl;
    return 0;
}