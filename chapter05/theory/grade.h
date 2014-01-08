#ifndef GUARD_grade_h
#define GUARD_grade_h
#include <vector>
#include <list>
#include "Student_info.h"

using std::vector;
using std::list;

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info&);
vector<Student_info> extract_fails_v1(vector<Student_info>&);
vector<Student_info> extract_fails_v2(vector<Student_info>&);
vector<Student_info> extract_fails_v3(vector<Student_info>&);
list<Student_info> extract_fails_v4(list<Student_info>&);
#endif
