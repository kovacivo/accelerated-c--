#include "grade.h"

#include <stdexcept>
#include <vector>
#include <list>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;
using std::list;

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade (const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s)
{
	return s.final_grade < 60;
}
// separate passing and failing student records: first try
vector<Student_info> extract_fails_v1(vector<Student_info>& students)
{
	vector<Student_info> pass, fail;

	for(vector<Student_info>::size_type i = 0; i != students.size(); ++i)
		if (fgrade(students[i]))
			fail.push_back(students[i]);
		else
			pass.push_back(students[i]);

	students = pass;
	return fail;
}

// separate passing and failing student records: second try
vector<Student_info> extract_fails_v2(vector<Student_info>& students)
{
	vector<Student_info> fail;

	vector<Student_info>::size_type i = 0; 
	
	while (i != students.size()) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
			students.erase(students.begin() + i);
		}
		else
			++i;
	}
	return fail;
}

// separate passing and failing student records: third try
vector<Student_info> extract_fails_v3(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();
	
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}

// separate passing and failing student records: fourth try - using list
list<Student_info> extract_fails_v4(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();
	
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}
