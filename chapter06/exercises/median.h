#ifndef GUARD_median_h
#define GUARD_median_h

// median.h - final version
#include <vector>
#include "Student_info.h"

double median(std::vector<double>);
double optimistic_median_analysis(const std::vector<Student_info>&);
double optimistic_median(const Student_info&);

#endif
