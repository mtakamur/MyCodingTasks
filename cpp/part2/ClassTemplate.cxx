#include "ClassTemplate.h"
#include <iostream>
using namespace std;

template <>
char* ClassTemplate<char*>::GetNumber()
{
    char* str="Class template override test.";
    return str;
}

int main()
{
	int a=10;
	char* chara="aaa";
	ClassTemplate<int> test(a);
	ClassTemplate<char*> chartest(chara);

	cout << test.GetNumber() << endl;
	cout << chartest.GetNumber() << endl;

	return 0;
}