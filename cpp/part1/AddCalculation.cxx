#include <iostream>

int main()
{
    int a[5] = {0, 1, 2, 3, 4};

    for(int i=0; i<5; i++)
    {// Addresses of elements
        printf("&a[%d] = %p\n", i, &a[i]);
    }
    for(int i=0; i<5; i++)
    {// Address calculation
        printf("&a[0] + %d = %p\n", i, &a[0] + i);
    }

    return 0;
}