// write a program to count how many times each distinct word appears in its input

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::cout << "Input the words ending with EOF: " << std::endl;

	// record all the words
	std::string word = "";
	std::vector<std::string> words;
	while (std::cin >> word)
		words.push_back(word);

	typedef std::vector<std::string>::size_type vector_size;
	
	// sort them all
	std::sort(words.begin(), words.end());

	vector_size vs = words.size();
	int count = 0;

	// for each distinct word count its occurences and output them
	// asign the first word first
	word = words[0];
	// for all the sorted words
	for (int i = 0; i < vs;++i) {
		if (word == words[i]) {
			count++;
			//std::cout << "currently " << word << std::endl;
		}
		else {
				// the word will be different
				//std::cout << "working with " << word << std::endl;
				std::cout << "Word " << word << " occurred " << count << " times." << std::endl;
				count = 0;
				word = words[i];
				count++;
				//std::cout << "Different word currently is " << word << std::endl;
		}
	}
	std::cout << "The last word was " << word << " and it occurred " << count << " times." << std::endl;

	return 0;	
}
