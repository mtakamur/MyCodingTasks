#include <iostream>

int main()
{
    int a = 0;
    int &b = a;// Declare b as a reference to a

    b = 10;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}