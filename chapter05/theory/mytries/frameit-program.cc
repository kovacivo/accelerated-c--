// program is from chapter 5.8 - theory; 
// it should define and use frameit function to frame the sentences in vector of words

#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <string>
#include <vector>
#include "frame-functions.h"

using std::cin;                     using std::setprecision;
using std::cout;                   
using std::streamsize;
using std::endl;                    using std::string;
using std::vector;


// program tests the functionality of split function 
int main()
{
	// string to input
	string s;	
	// vector holding the list of words
	vector<string> input_words;
	// vector holding the resulted picture
	vector<string> framed_words;

	// read and split every line of input
	while (cin >> s) 
		input_words.push_back(s);

	// frame the words
	framed_words = frameit(input_words);

	// print every word of vector
	for (vector<string>::const_iterator i = framed_words.begin(); i != framed_words.end(); ++i)
			cout << (*i) << endl;

	return 0;
}
