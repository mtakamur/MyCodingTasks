#include <iostream>
using namespace std;

enum ENUM{
    TEST1 = 0,
    TEST2 = 1,
    TEST3 = 2
};

ENUM ShowEnum(int number)
{
    if(number == 0)
    {
        return TEST1;
    }
    else if(number == 1)
    {
        return TEST2;
    }
    else if (number == 2)
    {
        return TEST3;
    }
    else
    {
        cout << "ERROR" << endl;
        return TEST1;
    }
}

int main()
{
    if(ShowEnum(0) == TEST1)
    {
        cout << "TEST1" << endl;
    }
    return 0;
}