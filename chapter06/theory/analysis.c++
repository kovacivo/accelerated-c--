#include "grade.h"
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include <algorithm>
#include "analysis.h"
#include <iostream>
#include <ostream>

using std::domain_error;
using std::vector;

void write_analysis(std::ostream& out, const std::string& name, double analysis(const vector<Student_info>&),
					const vector<Student_info>& did,
					const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << std::endl;
}

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}
