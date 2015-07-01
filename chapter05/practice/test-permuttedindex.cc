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
	for (vector<string>::iterator it = sentences.begin(); it != sentences.end(); ++it) {

		// for every string/sentence
		// generate temporary vector of strings - later it will be easier to make permutted index from it
		//for (string::const_iterator sit = it->begin(); sit != it->end(); ++sit) {
		vector<string> temporary_vector;

		string::iterator sit = (*it).begin();
		string::iterator jj = sit;
		while (sit != (*it).end()) {
			while ((sit != (*it).end() && isspace((*sit))))
				++sit;

			jj = sit;	
			while (jj != (*it).end() && !isspace((*jj)))
				++jj;
			if (sit != jj) {
					//cout << string(sit, jj) << endl;
					temporary_vector.push_back(string(sit, jj));
					sit = jj;
			}
		}

		// start printing rotations - that is: permutted index
		// first line is always indented by spaces of its whole length
		// find out the length of given sentence and print the spaces
		string::size_type spaces_to_indent = (*it).size();
		// number of spaces to print to separate index part from the remaining part of sentence
		int indent_spaces = 8;
		cout << string(spaces_to_indent + 1, ' ');

		// rotate every word in sentence and indent it apropriately
		for (vector<string>::const_iterator tit = temporary_vector.begin(); tit != temporary_vector.end(); ++tit) {
			cout << (*tit) << string(indent_spaces, ' ');
		}


		// print temporary_vector
		for (vector<string>::const_iterator tit = temporary_vector.begin(); tit != temporary_vector.end(); ++tit)
			cout << "$$$" << (*tit) << "$$$" << endl;

	}

	// output the result 
	//for (vector<string>::const_iterator it = sentences.begin(); it != sentences.end(); ++it)
	//		cout << "###" << (*it) << "###" << endl;

	return 0;
}
