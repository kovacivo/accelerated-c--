#include "strings.h"
#include <vector>
#include <string>

using std::vector; 
using std::string; 

std::vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;

	string_size i = 0;

	while (i != s.size())
	{
		// ignore leading blanks
		while (i != s.size() && isspace(s[i]))
			++i;

		// find end of next word
		string_size j = i;

		while (j != s.size() && !isspace(s[j]))
			j++;

		// if we found some nonwhite space characters
		if (i != j)
		{
			// copy s from starting at i and taking j - i chars
			ret.push_back(s.substr(i, j - i));
			i = j;
		}	
	}
	
	return ret;
	
}
