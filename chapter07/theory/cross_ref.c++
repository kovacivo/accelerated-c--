#include <iostream>
#include <istream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
// #include "cross_ref.h"

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


std::map<std::string, std::vector<int> > generate_cross_ref_table(std::istream& cin, std::vector<std::string> find_words(const std::string&) = split)
{
	std::string line;
	int line_number = 0;
	std::map<std::string,std::vector<int> > output;

	// input line
	while(getline(cin, line)) {
		++line_number;
	
		// split input line into words
		std::vector<std::string> words = split(line);

		// remember the position of each word
		for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++it)
			output[*it].push_back(line_number);
	}

	return output;

}
