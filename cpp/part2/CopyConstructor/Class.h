#ifndef Class_H
#define Class_H

#include <iostream>
using namespace std;

class Class
{
    private:
        int n_char = 0;
        char* str;
    
    public:
        Class(char* t_string);
        ~Class();
        void ShowStr();
};
#endif