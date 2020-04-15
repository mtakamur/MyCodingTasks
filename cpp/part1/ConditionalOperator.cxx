#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i=0;
    int j=1;

    cout << ((i > j)? i : j) << " is bigger." << endl;
    printf("%d is smaller.\n", ((j < i)? j : i));
    return 0;
}