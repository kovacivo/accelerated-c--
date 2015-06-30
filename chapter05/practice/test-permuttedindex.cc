// program is from exercise 5.1
// it should produce a permuted index. 
// A permuted index is one in which each phrase is indexed by every word in the phrase.

#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <string>
#include <vector>

#include "permuttedindex-functions.h"

using std::cin;                     using std::setprecision;
using std::cout;                   
using std::streamsize;
using std::endl;                    using std::string;
using std::vector;


// program tests the functionality of permutted index functions
int main()
{
	// string to input sentence
	string sentence;	

	// vector holding the list of sentences 
	vector<string> sentences;

	// read and save every sentence/line into vector of sentences
	while (getline(cin, sentence))
		sentences.push_back(sentence + '.');

	// for every sentence in vector of sentences generate a set of rotations
	// take every sentence/string
	// first print spaces plus one more space and then whole sentence
	// then parse sentence 
	// find out the longest sentence
	vector<string>::size_type longest_sentence = longest_string(sentences);
	cout << "Longest string/sentence had " << int(longest_sentence) << " chars." << endl;
	
	// for every string in vector of strings
	for (vector<string>::const_iterator it = sentences.begin(); it != sentences.end(); ++it) {

		// for every string/sentence
		// generate temporary vector of strings - later it will be easier to make permutted index from it
		//for (string::const_iterator sit = it->begin(); sit != it->end(); ++sit) {
		vector<string> temporary;
		for (string::const_iterator sit = it->begin(); sit != it->end(); ) {   // I'll update iterator/index within for loop
			cout << (*sit) << " " << endl;
			// skip spaces if there are any
			while (isspace((*sit)))
				++sit;
			// 

		// print temporary vector of strings from sentence
		}



	}

	// output the result 
	for (vector<string>::const_iterator it = sentences.begin(); it != sentences.end(); ++it)
			cout << "###" << (*it) << "###" << endl;

	return 0;
}
