#include <iostream>
using namespace std;

int GetFactorial(int n)
{
    if(n < 1) return 1;
    return n * GetFactorial(n - 1);
}

int main()
{
    int a = 5;
    cout << "The factorial of " << a << " = " << GetFactorial(a) << endl;
    return 0;
}