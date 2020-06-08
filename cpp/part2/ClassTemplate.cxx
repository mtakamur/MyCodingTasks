#include "ClassTemplate.h"
#include <iostream>
using namespace std;


int main()
{
	int a=10;
	ClassTemplate<int> test(a);

	a.GetNumber();
	return 0;
}