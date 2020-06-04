#ifndef VirtualFunc_H
#define VirtualFunc_H

#include <iostream>
using namespace std;

class Bird
{
    public:
        virtual void Sing()
        {
            cout << "A bird is singing" << endl;
        }
        virtual void Fly()
        {
            cout << "A bird is flying" << endl;
        }
};

class Crow : public Bird{
    public:
        void Sing()
        {
            cout << "A crow is singing" << endl;
        }
        void Fly()
        {
            cout << "A crow is flying" << endl;
        }
};

class Chicken: public Bird{
    public:
        void Sing()
        {
            cout << "A chicken is singing" << endl;
        }
        void Fly()
        {
            cout << "Chickens cannot fly" << endl;
        }
};

#endif