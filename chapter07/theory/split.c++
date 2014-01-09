// split function rewritten from 5.8 to use iterators
#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <string>
#include "split.h"

// true if the argument is whitespace, false otherwise
bool space(char c)
{
	return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c)
{
	return !isspace(c);
}

// split function itself defined using iterators
std::vector<std::string> split (const std::string& str)
{
	std::vector<std::string> ret;
	typedef std::string::const_iterator iter;

	iter i = str.begin();
	while (i != str.end())
	{
		// ignore leading blanks
		i = find_if(i, str.end(), not_space);

		// find end of next word
		iter j = find_if(i, str.end(), space);

		// if we found some nonwhite space characters
		if (i != str.end())
			ret.push_back(std::string(i,j));
		i = j;
	}
	
	return ret;

}
