#include <iostream>
#include "Format.h"
using namespace std;

int main(int argc, char* argv[])
{
    Format form(argc, argv);
    form.GenerateFormat();
	return 0;
}