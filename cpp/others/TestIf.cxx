#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int param = 5;
    vector<int> dec(5, 1);

    for(int i=5; i>0; i--)
    {
        if(param - 1 < 5)
        {
            cout << "case a, param = " << param << endl;
        }
        else if(param - 1 < 4)
        {
            cout << "case b, param = " << param << endl;
        }
    }

    return 0;
}