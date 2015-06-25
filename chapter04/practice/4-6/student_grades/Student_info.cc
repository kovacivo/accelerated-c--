// source file for `Student_info'-related functions
#include "Student_info.h"
#include "grade.h"
#include "median.h"

using std::istream;  using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
	// read and store the student's name and midterm and final exam grades
	is >> s.name >> s.midterm >> s.final;

	vector<double> temp;
	if (is) {
		
		// read homework grades
		double x;
		while (is >> x)
			temp.push_back(x);

		s.grade = grade(s.midterm, s.final, temp);
		
		is.clear();
	}

	temp.clear();
	return is;
}
