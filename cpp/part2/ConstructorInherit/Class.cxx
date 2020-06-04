#include "Class.h"

Human::Human(int t_age, const char* t_string)
{
    age = t_age;
    name = t_string;
    ShowAge();
    ShowName();
}

Human::~Human()
{}

void Human::ShowAge()
{
    cout << "Age is " << age << endl;
    return;
}

void Human::ShowName()
{
    cout << "Name is " << name << endl;
    return;
}

Student::Student(int age, char* t_string) : Human(age, t_string)
{}

void Student::ShowAge()
{
    cout << "Student's age is " << age << endl;
    return;
}

void Student::ShowName()
{
    cout << "Student's name is " << name << endl;
    return;
}