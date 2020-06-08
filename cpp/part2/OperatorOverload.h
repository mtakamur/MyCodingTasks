#ifndef OperatorOverload_H
#define OperatorOverload_H

class CIntArray{
    private:
        int* array;
        int nelements = 0;

    public:
        CIntArray(int number_of_elements);
        ~CIntArray();

        int GetNElements();
        int GetValue(int position);
        void SetValue(int position, int value);
        void ShowAllValue();
        int operator[](int ielement);
        void operator=(CIntArray target);
};

#endif