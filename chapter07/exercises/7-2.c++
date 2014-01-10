// counting words using maps - a.k.a hashes
#include <iostream>
#include <string>
#include <map>

int main()
{
	std::string s;
	std::map<std::string, int> counters;

	// read input keeping track of every word
	while (std::cin >> s)
		++counters[s];

	// output the words and their occurrences
	for(std::map<std::string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
		std::cout << it->first << "\t" << it->second << std::endl;
	}

	return 0;
}
