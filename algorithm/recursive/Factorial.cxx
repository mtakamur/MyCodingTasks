#include <iostream>
using namespace std;

int GetFactorial(int n);

int main()
{
    cout << GetFactorial(5) << endl;
    return 0;
}

int GetFactorial(int n)
{
    static int i;
    while(n>0)
    {
        i = n * GetFactorial(n - 1);
    }
    return i;
}