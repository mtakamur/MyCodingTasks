#include <iostream>
using namespace std;

int GetFibonacci(int n)
{
    if(n==1 || n==2) return 1;
    return GetFibonacci(n-1) + GetFibonacci(n-2);
}


int main()
{
    for(int i=1; i<10; i++)
    {
        cout << "The " << i << "th term of Fibonacci series = " << GetFibonacci(i) << endl;
    }
    return 0;
}