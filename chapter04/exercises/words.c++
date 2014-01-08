#include "words.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::istream;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::sort;

// this function will: 
// read the input from the user
// count the number of the words entered on the input 
// and count how many times each word occurred

void words_report(istream& is, vector<string>& words)
{
	string word;
	while(is >> word)
		words.push_back(word);
	sort(words.begin(),words.end());

	cout << "The number of entered words was " << words.size() << "." << endl;

	word = words[0];
	int count = 0;
	for (vector<string>::size_type i = 0; i < words.size();i++) {
		if (word == words[i])
			count++;
		else {
			cout << word << string(80 - word.length(), ' ') << count << endl;
			count = 1;
			word = words[i];
		}
	}
	cout << "The last word was " << word << " and occurred once." << endl;
}
