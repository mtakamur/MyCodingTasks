#ifndef Class_H
#define Class_H

#include <iostream>
using namespace std;

class Human
{
    protected:
        int age = 0;
        const char* name;
    
    public:
        Human(int age, const char* t_string);
        ~Human();
        virtual void ShowAge();
        virtual void ShowName();
};

class Student : public Human
{
    private:
        int student_id = 0;

    public:
        Student(int age, char* t_string);
        void ShowAge();
        void ShowName();
};

#endif