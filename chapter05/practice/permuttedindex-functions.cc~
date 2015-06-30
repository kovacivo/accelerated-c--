#include "permuttedindex-functions.h"
#include <string>
#include <vector>

using std::string;
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
