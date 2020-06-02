#include <iostream>
#include <cstring>
using namespace std;

void DefineStatic(int* &pa, int* &pb)
{
    static int a = 0;
    int b = 0;

    pa = &a;
    pb = &b;
    return;
}

void BreakMem()
{
    int vec[1000];
    memset(vec, 0, sizeof vec);
    return;
}

int main()
{
    int *a, *b;
    DefineStatic(a, b);
    cout << "a = " << *a << endl;
    cout << "b = " << *b << endl;

    BreakMem();

    cout << "a = " << *a << endl;
    cout << "b = " << *b << endl;

    return 0;
}