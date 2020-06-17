#include <iostream>
using namespace std;

int main()
{
	int a = 5;
	float b = 10.5;

	a = static_cast<int>(b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 0;
}