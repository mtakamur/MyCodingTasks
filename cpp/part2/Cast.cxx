#include <iostream>
using namespace std;

int main()
{
	int test = 0;
	char buf = '1';
	char* address = reinterpret_cast<char*>(&test);

	address[0] = '0';
	address[1] = '0';

	printf("Value of buf = %d\n", buf);

	cout << test << endl;
	cout << address << endl;
}