// program is from chapter 5.8; 
// it should define and use frameit function to frame the sentences in vector of words

#include <algorithm>
#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;                    using std::string;
using std::vector;

// helper function to find the longest string within vector of words
string::size_type longest_string(const vector<string>& string_vector) {
	// string size to be returned
	string::size_type longest_string = 0;
	
	// find longest string in vector
	for (vector<string>::const_iterator i = string_vector.begin(); i != string_vector.end(); ++i)
		if (longest_string < (*i).size())
			longest_string = (*i).size();

	cout << "In function longest_string the longest string was: " << longest_string << endl;
	return longest_string;
}

// function to frame the sentence into words returning framed vector - picture
vector<string> frameit(vector<string> s) {
	// frame to put in result
	vector<string> framed_strings;

	// longest string
  string::size_type max_string_length = longest_string(s);

  for (vector<string>::const_iterator i = s.begin(); i != s.end(); ++i) {
		// string tmp = '* ' + (*i) + string((max_string_length - (*i).size() - 1), ' ') + ' *';
		string spaces(longest_string(s) - (*i).size() - 1, ' ');
		string tmp = "* " + (*i) + spaces + " *"; 
		framed_strings.push_back(tmp);
	}
	return framed_strings;
}


// program tests the functionality of split function 
int main()
{
	string s;	
	vector<string> input_words;
	vector<string> framed_words;

	// read and split every line of input
	while (cin >> s) 
		input_words.push_back(s);


	// frame the words
	framed_words = frameit(input_words);

	// print every word of vector
	for (vector<string>::const_iterator i = framed_words.begin(); i != framed_words.end(); ++i)
			cout << "***" << (*i) << "***" << endl;
	

	return 0;
}

