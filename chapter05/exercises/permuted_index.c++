// program takes input lines and generates permuted indexes for each one

#include <iostream>
#include <vector>
#include <string>

// prints the vector content
void print_vector(const std::vector<std::string>& vec)
{
	for (std::vector<std::string>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
		std::cout << *iter + " ";
	std::cout << std::endl;
}

void rotate(std::vector<std::string>& sentence)
{
	
	std::vector<std::string>::iterator iter = sentence.begin();
	std::string word;
	std::vector<std::string>::size_type size = sentence.size();
	std::vector<std::string>::size_type j = 0;

	// int size = sentence.size();
	// int j = 0;
	while (j < size)
	{
		word = sentence[0];
		sentence.erase(iter);
		iter = sentence.begin();
		sentence.push_back(word);
		
		print_vector(sentence);
		j++;
	}
	

}

int main()
{

	std::cout << "Put the sentence here: ";
	std::string word;
	std::vector<std::string> sentence;
	
	while(std::cin >> word)
		sentence.push_back(word);
	
	std::cout << "You entered:" << std::endl;
 	print_vector(sentence);
	
	std::cout << std::endl;
	rotate(sentence);


	return 0;
}
