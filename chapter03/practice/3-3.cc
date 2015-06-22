// a program to count how many times each distinct word appears in its input
// input: number of words
// input: searched word
// result: number of times searched word was on input

#include <algorithm>
#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <string>
#include <vector>

using std::cin;             using std::sort;
using std::cout;            using std::streamsize;
using std::endl;            using std::string;
using std::setprecision;    using std::vector;

int main()
{
  cout << "This program computes and prints how many times searched word appears in input." << endl;

  cout << "Enter searched word: ";
  string searched_word;
  cin >> searched_word;

	// ask for and read the numbers 
	cout << "Enter all your words, followed by end-of-file (CTRL+D): ";
	vector<string> words;
	string word;
	// invariant: `words' contains all the words read so far
	while (cin >> word)
		words.push_back(word);

	// check that the user entered some words
	typedef vector<int>::size_type vec_sz;
	vec_sz words_size = words.size();
	if (words_size == 0) {
		cout << endl << "You must enter your words. Please try again." << endl;	
		return 1;
	}

	// sort the integers
	sort(words.begin(), words.end());
  
  // find searched word in sorted vector of words and tell its counts 
  int i = 0;
  int count = 0;
  while (i < words_size) {
  	if (searched_word == words[i])
			count++;
		i++;
  }

  // print the results
	if (count > 0)
		cout << "Word *** " << searched_word << " *** was " << count << " times on input." << endl;
	else
		cout << "Word *** " << searched_word << " *** was NOT found on input." << endl;

  // end program
  cout << "Program now ends." << endl;
	return 0;
}
