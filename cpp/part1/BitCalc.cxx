#include <iostream>
using namespace std;

int main()
{
    int val = 0;
    cin >> val;

    if((val & 1) || (val & 1<<1))
    {
        val >>= 2;
        val ++;
        val <<= 2;
    }
    cout << val << endl;
    return 0;
}