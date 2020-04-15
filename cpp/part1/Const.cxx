#include <iostream>
using namespace std;

int main()
{
    int i=0, j=0;
    const int *p;

    p = &i;
    cout << "p = " << p << endl;

    p = &j;
    cout << "p = " << p << endl;

    /* Forbidden */
    //*p = 1;
    //cout << "*p = " << p << endl;
    return 0;
}