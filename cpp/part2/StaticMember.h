#ifndef StaticMember_H
#define StaticMember_H

class StaticMember
{
    private:
        static int number_of_objects;

    public:
        StaticMember();
        ~StaticMember();
        static void ShowNumber();
};

#endif