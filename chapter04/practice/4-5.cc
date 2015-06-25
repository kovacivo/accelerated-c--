// Write a function that reads words from an input stream and stores them in a
// vector . Use that function both to write programs that count the number of words in
// the input, and to count how many times each word occurred.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;                    using std::string;
using std::setw;
using std::istream;
using std::vector;

// function to read words from input stream storing them into vector
istream& read_words(istream& in, vector<string>& words) {
	if (in) {
		// get rid of previous contents
		words.clear();

		// read words into vector
		string word;
		while (in >> word)
			words.push_back(word);

		// clear the stream so that input will work for the next student
		in.clear();
	}

	return in;
};

// function to count the number of words in the input
int count_words(const vector<string>& words) {
	int count = int(words.size());
	return count;
}

// function to count occurrence of each word on input
void count_occurrences(vector<string>& words){
	sort(words.begin(), words.end());
  
	int maxlinelen = 40;

  // number of times given word occurred - at least every word will be 1 time
	int count = 1;

	// to record also the last word which is not printed out normally 
  int last_word;
	for(int i = 1; i < int(words.size());i++) {
		// the word is contained more than once
		if (words[i] == words[i-1]) {
			count++;
			last_word = i;
		// different word follows
		} else {
			// print out the word's occurrence with padding
			cout << words[i-1] << string(maxlinelen - words[i-1].length() + 1, ' ') << count << endl;
			count = 1;
		}
		
	}

	// print out the last word not tracked
	cout << words[last_word] << string(maxlinelen - words[last_word].length() + 1, ' ') << count << endl;
}

int main()
{
  // program header
  cout << "Program counts the number of words entered as well as counts how many times each word occurred";
	cout << "First please enter all the words you are interested in: ";

	vector<string> words;

	// program main body
  // get the words into vector of strings from user
	cout << "Please enter the words followed by EOF (CTRL+D): ";
	read_words(cin, words);

	// count the number of words entered	
	int word_count = count_words(words);

  // print results
	cout << "You entered " << word_count << " words." << endl;	
	cout << "See please below how many times each word was on input." << endl << endl;	

  // print word occurrences
	count_occurrences(words);

  // program tail
  cout << "Program now ends." << endl;
	return 0;
}
