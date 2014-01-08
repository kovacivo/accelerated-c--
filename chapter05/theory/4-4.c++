// write a program to calculate the squares of int values up to 100
// the program should write two columns: the first list the value; the second contains the square of that value
// use setw to manage output so that the values line up in columns
#include <iostream>
#include <iomanip>

using std::streamsize;
using std::setw;

int main()
{
	streamsize prec = std::cout.precision();
	streamsize width = std::cout.width();
	double x = 0;
	for (int i = 0; i <= 1000; ++i) {
		std::cout << std::left << std::showbase << std::showpos << std::dec <<  i << std::setw(30) << std::setprecision(60) << std::hex << int(x * x) << std::endl;
		x++;
		// std::cout.width(10);
	}

	return 0;
}
