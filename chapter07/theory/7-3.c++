// generating cross references table
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

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

int main()
{
	std::map<std::string, std::vector<int> > output = generate_cross_ref_table(std::cin);

	// output the results
	for(std::map<std::string, std::vector<int> >::const_iterator it = output.begin(); it != output.end(); ++it) {
	
		// output word
		std::cout << it->first << " is on the line(s): ";
		
		// followed by one or more numbers of lines
		std::vector<int>::const_iterator line_it = it->second.begin();
		std::cout << *line_it; // prints the first line number

		++line_it;
		// prints the remaining number of lines, if there are any
		while (line_it != it->second.end()) {
			std::cout << ", " << *line_it;
			++line_it;
		}

		// prints new line after each word
		std::cout << std::endl;
	}
	return 0;
}
