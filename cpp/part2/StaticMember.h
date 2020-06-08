#ifndef StaticMember_H
#define StaticMember_H

class StaticMember
{
    private:
        static int n;

    public:
        StaticMember(int number);
        void ShowValue();
};

#endif