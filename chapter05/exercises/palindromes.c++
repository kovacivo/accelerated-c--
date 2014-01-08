// program from its input identifies and prints out the palindroms
// palindroms - Anna Abba Oto korok kajak krk grg blb tahat radar rotor madam oko bob kolok letel aha oco joj
#include <iostream>
#include <cctype>
#include <vector>
#include <list>
#include <forward_list>

bool ispalindrom(std::string& word)
{
	std::string::iterator it1, it2;
	it1 = word.begin();
	it2 = word.end();

	int i = 0;
	int j = word.size() - 1;
	int size = word.size();

	std::cout << std::endl;
	while ((size > 0) && (i <= size / 2))
	{
		// if it is space skip to another character updating position
		if (isspace(word[i])) {
			i++;
			continue;
		}
		// if it is space skip to another character updating position
		if (isspace(word[j])) {
			j--;
			continue;
		}

		// if the letters don't match, it is not a palindrome
		if (word[i] != word[j])
			return false;
		i++; j--; size--;
	}
	// now it should be clear it is a palindrome
	return true;
}

int main()
{
	std::cout << "Put the word to be a palindrome: ";
	std::string word;
	// acquire a whole line and put it into vector
	// typedef std::vector<std::string> Slova;
	typedef std::list<std::string> Slova;
	Slova words;
	// std::vector<std::string> words;
	while (getline(std::cin, word))
		words.push_back(word);
	// for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
	for (Slova::iterator it = words.begin(); it != words.end(); it++)
	{
		std::cout << "The word: \"" + (*it) + "\"" + ((ispalindrom(*it)) ? " is palindrome." : " is NOT palindrome.");
	}
	std::cout << std::endl;

	return 0;
}
