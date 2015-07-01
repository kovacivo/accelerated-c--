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


int main()
{
	// string to input sentence
	string sentence;	

	// vector holding the list of sentences 
	vector<string> sentences;

	// read and save every sentence/line into vector of sentences
	while (getline(cin, sentence))
		// adding dashes in order to distinguish the end of word
		sentences.push_back(sentence + "--------");

	// for every sentence in vector of sentences generate a set of rotations
	
	// first I need to get a vector of strings to rotate them later
	// I need to split the vector of strings in each sentence to every word
	vector<string>::size_type longest_sentence = longest_string(sentences);
	//cout << "Longest string/sentence had " << int(longest_sentence) << " chars." << endl;
	
	// for every sentence in vector of sentences entered sooner
	for (vector<string>::iterator it = sentences.begin(); it != sentences.end(); ++it) {

		// generate temporary vector of strings - later it will be easier to make permutted index from it
		// temporary vector holding the words from one particular sentence
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
					temporary_vector.push_back(string(sit, jj));
					sit = jj;
			}
		}

		// now I've got the words in a separate vector - temporary vector - and need to rotate them
		// rotate every word in sentence and indent it apropriately - changing the vector in place
		for (vector<string>::iterator tit = temporary_vector.begin(); tit != temporary_vector.end(); ++tit){
			for (vector<string>::iterator rit = temporary_vector.begin(); rit != temporary_vector.end(); ++rit){
				cout << (*rit) << " ";
			}
			// take the very first item/word from the vector of words
			string tmp = temporary_vector.front();
			// delete the word at the very beginning
			temporary_vector.erase(temporary_vector.begin());
			// put deleted word at the end of vector of words
			temporary_vector.push_back(tmp);
			cout << endl;
		}
	}
	
	return 0;
}
