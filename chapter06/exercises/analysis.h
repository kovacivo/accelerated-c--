#ifndef GUARD_analysis_h
#define GUARD_analysis_h
#include <vector>
#include "Student_info.h"
#include <ostream>
#include <iostream>

using std::vector;

void write_analysis(std::ostream& out, const std::string&, double analysis(const vector<Student_info>&),const vector<Student_info>&, const vector<Student_info>&);
double median_analysis(const vector<Student_info>&);
double average_analysis(const vector<Student_info>&);
double optimistic_analysis(const vector<Student_info>&);


#endif
