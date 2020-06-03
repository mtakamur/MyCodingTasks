#include <iostream>
using namespace std;

int main()
{
    int* array;
    array = new int[10];
    for(int i=0; i<10; i++)
    {
        array[i] = i;
    }

    for(int i=0; i<10; i++)
    {
        cout << &array[i] << endl;
    }

    delete [] array;

    return 0;
}