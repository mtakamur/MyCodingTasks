#include "Class.h"

Class::Class(char* t_string)
{
    str = new char{*t_string};
}

Class::~Class()
{
}

void Class::ShowStr()
{
    cout << str << endl;
    return;
}