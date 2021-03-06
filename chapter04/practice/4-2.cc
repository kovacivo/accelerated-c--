// Write a program to calculate the squares of int values up to 100. The program
// should write two columns: The first lists the value; the second contains the square of
// that value. Use setw (described above) to manage the output so that the values line up
// in columns.

// 4-3: What happens if we rewrite the previous program to allow values up to but not
// including 1000 but neglect to change the arguments to setw ? Rewrite the program to
// be more robust in the face of changes that allow i to grow without adjusting the setw
// arguments.

// 4-4: Now change your squares program to use double values instead of int s. Use
// manipulators to manage the output so that the values line up in columns.

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
  cout << "Program computes squares of int numbers up to 100." << endl;
	for (int i = 1; i <= 1000; i++) {
		cout << i << setw(30) << i * i << endl;
		cout << i << setw(30) << setprecision(2) <<  (double)i * (double)i << endl;
  }

  cout << "Program now ends." << endl;
	return 0;
}

