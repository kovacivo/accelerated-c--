// program sorts out and prints the lower and uppercase words from its input

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main()
{
	// acquire a strings from users
	std::cout << "Input the content to be checked." << std::endl;
	
	std::vector<std::string> lower, upper;
	std::string input_str;

	// put the strings into the vector reading the whole line of input
	while(std::cin >> input_str)
	{
		if (islower(*input_str.begin()))
			lower.push_back(input_str);
		else
			upper.push_back(input_str);
	}

	// output the lowercase words
	std::cout << "Lowercase strings are here: ";
	for (std::vector<std::string>::iterator it = lower.begin(); it != lower.end(); it++)
		std::cout << (*it) + " ";
	std::cout << std::endl;

	// output the uppercase words
	std::cout << "Uppercase strings are here: ";
	for (std::vector<std::string>::iterator it = upper.begin(); it != upper.end(); it++)
		std::cout << (*it) + " ";
	std::cout << std::endl;

}
