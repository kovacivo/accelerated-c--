// write a program to report the length of the longest and shortest string in its input

#include <iostream>

int main()
{
	std::cout << "Start entering the strings. When finished, press EOF." << std::endl;
	std::string word, shortest_word, longest_word;
	int shortest = 0, longest = 0;

	// ask for the first word to start with
	std::cin >> word;
	shortest = longest = word.size();
	shortest_word = word;

	// read the words to determine their sizes
	while (std::cin >> word) {
		if (word.size() > longest) {
			longest = word.size();
			longest_word = word;
		} else {
				if (word.size() <= shortest) {
					shortest = word.size();
					shortest_word = word;
				}
		}
	}

	// show the results
	std::cout << "The shortest word had " << shortest << " characters and it was *** " << shortest_word << " ***." << std::endl;
	std::cout << "The longest word had " << longest << " characters and it was *** " << longest_word << " ***." << std::endl;
	return 0;
}
