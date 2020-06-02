#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a;
    string str;

    cin >> a;
    cin.ignore();

    getline(cin, str);
    cout << str << endl;
    return 0;
}