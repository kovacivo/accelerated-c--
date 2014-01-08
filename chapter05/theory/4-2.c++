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
	for (int i = 0; i <= 1000; ++i) {
		std::cout << setw(10) << i << std::setw(70) << i*i << std::endl;
		// std::cout.width(10);
	}

	return 0;
}
