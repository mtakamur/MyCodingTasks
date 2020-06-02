#include <iostream>

void ShowValue(int &val)
{
    int val_cp = val;
    val = 0;
    
    printf("val    = %d\n", val);
    printf("val_cp = %d\n", val_cp);
    return;
}

int main()
{
    int a = 10;
    ShowValue(a);
    return 0;
}