// program is from chapter 5.8 - theory; 
// it should use vcat function to vertically join two pictures and frame them together

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
	// vector holding the list of words for first picture
	vector<string> first_words;

	// vector holding the list of words for second picture
	vector<string> second_words;

	// vector holding the resulted picture
	vector<string> framed_words;

	// read and split every line of input for first picture
	while (cin >> s) 
		first_words.push_back(s);

	cin.clear();
	// read and split every line of input for second picture
	while (cin >> s) 
		second_words.push_back(s);

	// vertically join the two pictures together
	framed_words = vcat(first_words, second_words);

	// output the result of vcat
	for (vector<string>::const_iterator i = framed_words.begin(); i != framed_words.end(); ++i)
			cout << (*i) << endl;

	return 0;
}
