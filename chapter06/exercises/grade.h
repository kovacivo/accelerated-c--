#ifndef GUARD_grade_h
#define GUARD_grade_h
#include <vector>
#include "Student_info.h"

using std::vector;

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
double grade_aux(const Student_info&);
bool fgrade(const Student_info&);

#endif
