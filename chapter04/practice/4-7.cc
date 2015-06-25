//Write a program to calculate the average of the numbers stored in a vector<double> .

#include <algorithm>
#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;                    using std::string;
using std::setw;
#ifndef _MSC_VER
using std::max;                     using std::vector;
#else
using std::vector;

#include "../minmax.h"
#endif

int main()
{
  // program header
  cout << "Program computes the average of the numbers stored in a vector." << endl;

	// program main body
  // get the numbers into vector from user
	cout << "Please enter the numbers followed by EOF (CTRL+D): ";
  double number;
	vector<double> numbers;
	while (cin >> number)
		numbers.push_back(number);

	// compute the sum of all the numbers in vector
	double sum = 0;
	for (int i = 0; i < numbers.size(); i++)
		sum = sum + numbers[i];

  // print results
	cout << "The average of numbers you entered is " << setprecision(5) << sum / double(numbers.size()) << endl;	

  // program tail
  cout << "Program now ends." << endl;
	return 0;
}

