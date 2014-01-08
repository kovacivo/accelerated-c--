#ifndef GUARD_classify_h
#define GUARD_classify_h

// classify.h - final version
#include <vector>
#include "Student_info.h"

std::vector<Student_info> extract_fails(std::vector<Student_info>&);
bool pgrade(const Student_info&);

#endif
