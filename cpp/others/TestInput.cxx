#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int counter = 0;
	string str;
	string date[3];
	stringstream ss;

	cout << "Input date > ";
	getline(cin, str);
	ss << str;

	while(getline(ss, date[counter], '/')) counter++;

	cout << "Year = " << date[0] << endl;
	cout << "Month = " << date[1] << endl;
	cout << "Date = " << date[2] << endl;
	return 0;
}