#include <iostream>
#include "VirtualFunc.h"

int main()
{   
    Bird* crow = new Crow();
    Bird* chicken = new Chicken();

    crow->Sing();
    crow->Fly();
    
    chicken->Sing();
    chicken->Fly();
    return 0;
}