#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nelements = 5;
    vector<int> vec(nelements, 0);
    
    vec.clear();
    vec.shrink_to_fit();

    vec.~vector();

    return 0;
}