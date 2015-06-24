// a program to report the length of the longest and shortest string in its input.
// input: words
// result: length of shortest and longest string

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
  cout << "This program prints the length of shortest and longest string." << endl;

	// ask for and read the words 
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
		cout << "You must enter your words. Please try again." << endl;	
		return 1;
	}

	// sort the words 
	sort(words.begin(), words.end());
  
  // find min and max word in sorted vector of words 
  int i = 1;   // index in vector words
  int min = words[0].length(); // length of shortest string
  int max = words[0].length(); // length of longest string

  while(i < words_size) {
		if (words[i].length() > max)
			max = words[i].length();
		if (words[i].length() < min)
			min = words[i].length();
		i++;
	}

  // print the results
	cout << "The longest string had " << max << " chars " << " and the shortest string had " << min << " chars." << endl;

  // end program
  cout << "Program now ends." << endl;
	return 0;
}
