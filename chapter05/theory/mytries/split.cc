// program is from chapter 5.6; it should define and use split function to split the sentence into words

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

// function to split the sentence into words returning vector of words
vector<string> split(string s) {
	vector<string> strings;

	typedef string::size_type string_size;
	string_size i = 0;
	string_size j = 0;
	string tmp;
	
	// dokial nie je koniec retazca - moze mat aj medzery
	while (i != s.size()) {
		// preskoc uvodne medzery a najdi zaciatok slova
		while ((isspace(s[i])) && (i != s.size()))
			++i;	

		// najdi koniec slova - zacina prvou medzerou
		j = i;
		while ((!isspace(s[j])) && (j != s.size())) 
			++j;

		// nasli sme slovo
		if (i != j) {
			// skopiruj najdene slovo do vektora slov
			strings.push_back(s.substr(i,j - i));
			i = j;
		}
	}

	return strings;
}

// program tests the functionality of split function 
int main()
{
	string s;	

	// read and split every line of input
	while (getline(cin, s)) {
		vector<string> vector_of_strings = split(s);

		// print every word of vector
		for (vector<string>::size_type i = 0; i != vector_of_strings.size(); ++i)
			cout << "***" << vector_of_strings[i] << "***" << endl;
	}

	return 0;
}

