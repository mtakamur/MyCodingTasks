#include "StaticMember.h"
#include <iostream>
using namespace std;

int StaticMember::number_of_objects;

StaticMember::StaticMember()
{
	number_of_objects++;
}

StaticMember::~StaticMember()
{
	number_of_objects--;
}

void StaticMember::ShowNumber()
{
	cout << "Number of objects in class StaticMember = " << number_of_objects << endl;
	return;
}

int main()
{
	StaticMember::ShowNumber();

	StaticMember a, b;

	StaticMember::ShowNumber();
	return 0;
}