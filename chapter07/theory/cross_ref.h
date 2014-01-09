#ifndef GUARD_cross_ref_h
#define GUARD_cross_ref_h
#include <vector>
#include <map>
#include <string>

// std::map<std::string, std::vector<int> > generate_cross_ref_table(std::istream&, std::vector<std::string> split(const std::string&));
std::map<std::string, std::vector<int> > generate_cross_ref_table(std::istream&);
#endif
