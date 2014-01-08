// write a function that reads words from an input stream and stores them in a vector
// use that function both to write programs that count the number of words in the input
// and to count how many times each word occured

#include <iostream>
#include <vector>
#include <algorithm>
#include "words.h"

using std::vector; using std::string; using std::cin; using std::cout; using std::endl; using std::sort;

int main()
{
	vector<string> words;
	// request some words from user and store them in a vector of strings
	std::cout << "Put some words, then finish inputing EOF." << std::endl;

	// enter the words, count them and give a report
	words_report(cin, words);

	return 0;
}
