#ifndef __frame_functions__
#define __frame_functions__
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
string::size_type longest_string(const vector<string>& string_vector);

// function to frame the sentence into words returning framed vector - picture
vector<string> frameit(const vector<string> s); 

// function to vertically join two vectors of words to create one picture
vector<string> vcat(const vector<string> top, const vector<string> bottom);

// function to horizontally join two vectors of words to create one picture
vector<string> hcat(const vector<string> left, const vector<string> right);

#endif /* frame-functions.h */
