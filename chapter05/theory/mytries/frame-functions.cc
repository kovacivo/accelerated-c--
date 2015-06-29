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
// returns the length of longest string
string::size_type longest_string(const vector<string>& string_vector) {
	// string size to be returned
	string::size_type longest_string = 0;
	
	// find longest string in vector
	for (vector<string>::const_iterator i = string_vector.begin(); i != string_vector.end(); ++i)
		if (longest_string < (*i).size())
			longest_string = (*i).size();

	return longest_string;
}

// function to frame the sentence into words returning framed vector - picture
vector<string> frameit(vector<string> s) {

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
