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
    cout << ShowEnum(0) << endl;
    cout << ShowEnum(1) << endl;
    cout << ShowEnum(2) << endl;
    return 0;
}