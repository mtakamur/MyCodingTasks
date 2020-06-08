#include "StaticMember.h"
#include <iostream>
using namespace std;

StaticMember::StaticMember(int number)
{
	n = number;
}

void StaticMember::ShowValue()
{
	cout << n << endl;
	return;
}

int main()
{
	StaticMember a(100), b(200);

	a.ShowValue();
	b.ShowValue();
	a.ShowValue();
	return 0;
}