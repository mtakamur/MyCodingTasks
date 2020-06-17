#include <iostream>
using namespace std;

int main()
{
	int *a = new int(5);
	float *b = new float(10.5);

	a = reinterpret_cast<int*>(b);

	cout << "a = " << *a << endl;
	cout << "b = " << *b << endl;
	return 0;
}