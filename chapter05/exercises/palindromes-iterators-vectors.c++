// program from its input identifies and prints out the palindroms
// palindroms - for instance words like: Anna Abba Oto korok kajak krk grg blb tahat radar rotor madam oko bob kolok letel aha oco joj
#include <iostream>
#include <cctype>
#include <vector>

bool ispalindrom(const std::string& word)
{
	std::string::const_iterator it1, it2;
	it1 = word.begin();
	it2 = word.end() - 1;

	int size = word.size();

	std::cout << std::endl;
	while ((size > 0) && (size >= word.size()/2))
	// while ((size > 0))
	{
		// if it is space skip to another character updating position for front iterator
		if (isspace(*it1)) {
			it1++;
			continue;
		}
		// if it is space skip to another character updating position for back iterator
		if (isspace(*it2)) {
			it2--;
			continue;
		}

		// if the letters don't match, it is not a palindrome
		if (*it1 != *it2)
			return false;
		it1++; it2--; size--;
	}
	// now it should be clear it is a palindrome
	return true;
}

int main()
{
	// acquire a whole line and put it into a list
	std::cout << "Put the word to be a palindrome: ";
	std::string word;

	typedef std::vector<std::string> Words;
	Words words;
	while (getline(std::cin, word))
		words.push_back(word);

	// parse the words and find out which ones are palindromes
	for (Words::iterator it = words.begin(); it != words.end(); it++)
	{
		std::cout << "\"" + (*it) + "\"" + ((ispalindrom(*it)) ? " is palindrome." : " is NOT palindrome.");
	}
	std::cout << std::endl;

	return 0;
}
