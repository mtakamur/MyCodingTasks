#include <iostream>
#include "OperatorOverload.h"
using namespace std;

CIntArray::CIntArray(int number_of_elements)
{
    nelements = number_of_elements;
    array = new int[nelements];
}

CIntArray::~CIntArray()
{}

int CIntArray::GetNElements()
{
    return nelements;
}

void CIntArray::SetValue(int position, int value)
{
    if(position<0 || position>=nelements) return;
    array[position] = value;
}

int CIntArray::GetValue(int position)
{
    if(position<0 || position >= nelements) return -1;

    return array[position];
}

void CIntArray::ShowAllValue()
{
    for(int i=0; i<nelements; i++)
    {
        cout << array[i];
    }
    cout << endl;
    return;
}

int CIntArray::operator[](int ielement)
{
    if((ielement<0) || (ielement>=nelements))
    {
        cout << "Wrong element ID" << endl;
        return -1;
    }
    else
    {
        return GetValue(ielement);
    }
}

void CIntArray::operator=(CIntArray source)
{
    if(nelements < source.GetNElements())
    {
        cout << "Target size is smaller than the original" << endl;
    }
    else
    {
        for(int i=0; i<source.GetNElements(); i++)
        {
            array[i] = source.GetValue(i);
        }
    }
    
}

int main()
{
    CIntArray a(10);
    CIntArray b(20);

    for(int i=0; i<10; i++)
    {
        a.SetValue(i, i);
    }

    b = a;

    a.ShowAllValue();
    b.ShowAllValue();

    cout << a[9] << endl;
    
    return 0;
}