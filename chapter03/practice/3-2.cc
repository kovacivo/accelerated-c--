// a program to compute and print the quartiles (that is, the quarter of the numbers with the largest values, the next highest quarter, and so on) of a set of integers.

#include <algorithm>
#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <string>
#include <vector>

using std::cin;             using std::sort;
using std::cout;            using std::streamsize;
using std::endl;            using std::string;
using std::setprecision;    using std::vector;

int main()
{
  cout << "This program computes and prints the quartiles of a set of integers from the largest quarter up to the lowest quarter)" << endl;

	// ask for and read the numbers 
	cout << "Enter all your integers, followed by end-of-file (CTRL+D): ";
	vector<int> integers;
	int x;
	// invariant: `integers' contains all the numbers read so far
	while (cin >> x)
		integers.push_back(x);

	// check that the user entered some numbers
	typedef vector<int>::size_type vec_sz;
	vec_sz integers_size = integers.size();
	if (integers_size == 0) {
		cout << endl << "You must enter your numbers.  "
		                "Please try again." << endl;	
		return 1;
	}

	// sort the integers
	sort(integers.begin(), integers.end());

  int quartile_size = integers.size()/4;
  cout << "Quartile size is " << quartile_size << endl;

  int tmp = 0;
  while(integers.size() > 0) {
    tmp = 0;
    while (tmp < quartile_size) {
    	cout << integers[(integers.size()-1)] << " ";
  	  integers.pop_back(); 
      tmp++;
    }
    cout << endl;
  }

  cout << "Program now ends." << endl;
	return 0;
}

