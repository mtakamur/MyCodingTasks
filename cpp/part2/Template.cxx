#include <iostream>
using namespace std;

template <typename TYPE>
TYPE Max(TYPE a, TYPE b)
{
	return (a > b) ? a : b;
}

int main()
{
	void *p;
	char str[100];
	int num;

	p = Max<void*>(str, &num);
	cout << "より大きいアドレスは "
		 << p << "です。" << endl;

	return 0;
}