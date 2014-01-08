#include <iostream>
#include <string>
#include <vector>
#include "strings.h"

int main()
{
	std::string s;
	// read and split each line of input
	while (getline(std::cin, s))
	{
		std::vector<std::string> v = split(s);

		// write each word in v
		for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
			std::cout << v[i] << std::endl;
	}

	return 0;
}
