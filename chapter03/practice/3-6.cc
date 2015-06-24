// The average-grade computation in §3.1/36 might divide by zero if the student
// didn't enter any grades. Division by zero is undefined in C++, which means that the
// implementation is permitted to do anything it likes. What does your C++
// implementation do in this case? Rewrite the program so that its behavior does not
// depend on how the implementation treats division by zero.

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
  cout << "This program shows how GNU gcc implementation treats division by zero." << endl;
	cout << "This expression: 4 / 0 = leaves the following result: 'Floating point exception'" << endl;
  cout << 4 / 0 << endl;

  // end program
  cout << "Program now ends." << endl;
	return 0;
}
