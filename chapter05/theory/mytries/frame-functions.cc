#include "frame-functions.h"

#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <string>
#include <vector>

using std::cin;                     using std::setprecision;
using std::cout;                   
using std::streamsize;
using std::endl;                    using std::string;
using std::vector;

// helper function to find the longest string within vector of words
string::size_type longest_string(const vector<string>& string_vector) {
	// returns the length of longest string
	// string size to be returned
	string::size_type longest_string = 0;
	
	// find longest string in vector
	for (vector<string>::const_iterator i = string_vector.begin(); i != string_vector.end(); ++i)
		if (longest_string < (*i).size())
			longest_string = (*i).size();

	return longest_string;
}

// function to frame the sentence into words returning framed vector - picture
vector<string> frameit(const vector<string> s) {

	// frame to put in result
	vector<string> framed_strings;

	// longest string
  string::size_type max_string_length = longest_string(s);

  // first put the top of frame
  framed_strings.push_back(string( max_string_length + 4, '*'));
  framed_strings.push_back('*' + string( max_string_length + 2, ' ') + '*');

  // put the text into picture
  for (vector<string>::const_iterator i = s.begin(); i != s.end(); ++i) {
		framed_strings.push_back("* " + (*i) + string(max_string_length - (*i).size(), ' ') + " *");
	}

  // at the end put the bottom of frame
  framed_strings.push_back('*' + string( max_string_length + 2, ' ') + '*');
  framed_strings.push_back(string( max_string_length + 4, '*'));

	return framed_strings;
}

// function to vertically join two vectors of words to create one picture
vector<string> vcat(const vector<string> top, const vector<string> bottom) {

	// frame to put in result
	vector<string> framed_strings;

	// first put the top picture
	framed_strings = top;

	// then add (insert) the second picture
	framed_strings.insert(framed_strings.end(), bottom.begin(), bottom.end());

	// frame the whole picture
	return frameit(framed_strings);
}

// function to horizontally join two vectors of words to create one picture
vector<string> hcat(const vector<string> left, const vector<string> right) {

	// frame to put in result
	vector<string> framed_strings;

	// need to know which of those two is bigger picture
	vector<string>::size_type left_size = left.size();
	vector<string>::size_type right_size = right.size();
	
	// if the left picture is bigger
	if (left_size > right_size) {

		// for every line of words in left vector
		vector<string>::const_iterator rit = right.begin();
		for (vector<string>::const_iterator lit = left.begin(); lit != left.end(); ++lit) {
			// if there is nothing on right side, just skip it
			if (rit == right.end()) {
				framed_strings.push_back(string((*lit) + " " + " "));	
				continue;
			} else {
				framed_strings.push_back(string((*lit) + " " + (*rit)));	
				++rit;
			}
		}

	// otherwise the right picture is bigger
	} else {
		// for every line of words in left vector
		vector<string>::const_iterator lit = left.begin();
		for (vector<string>::const_iterator rit = right.begin(); rit != right.end(); ++rit) {
			// if there is nothing on right side, just skip it
			if (lit == left.end()) {
				framed_strings.push_back(string((*rit) + " " + " "));	
				continue;
			} else {
				framed_strings.push_back(string((*lit) + " " + (*rit)));	
				++lit;
			}
		}
	}

	// frame the whole picture
	return frameit(framed_strings);
}
