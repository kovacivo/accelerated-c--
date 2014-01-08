#include <algorithm>
#include <iostream>
#include <vector>
// program/function finds web addresses (URLs) that are embedded in a string
// the function scans the document (stored in a string) and find all the URLs in it
// a URL is a sequence of characters of the form: protocol-name://resource-name
// where protocol-name contains only letters
// and resource-name contains only letters, digits and certain punctuation characters
// the function will take a string argument and will look for instances of :// in that string
// each time such an instance will be found, we'll look for the protocol-name that precedes it and resource-name that follows it
// we want our function to find all the URLs in its input, it will return a vector<string> with one element for each URL

std::vector<std::string> find_urls(std::string& s)
{
	// vector to return
	std::vector<std::string> vec;
	std::string::iterator it = s.begin();
	std::string search_seq = "://";

	it = std::search (s.begin(), s.end(), search_seq.begin(), search_seq.end());

	// print out the URL
	/*
	std::cout << *it << std::endl;
	for (std::string::iterator i = s.begin(); i != it; ++i)
	{
		std::cout << *i;
	}
	std::cout << std::endl;
	*/

	// create a new string named url
	std::string url(s.begin(), it);
	// std::cout << url << std::endl;

	// print out the resource name
	/*
	std::cout << *it << std::endl;
	for (std::string::iterator i = it+3; i != s.end(); ++i)
	{
		std::cout << *i;
	}
	std::cout << std::endl;
	*/

	// create a new string named resource
	std::string resource(it+3,s.end());
	// std::cout << resource << std::endl;
	
	vec.push_back(std::string(url + " -> " + resource));

	
	return vec;
}

int main()
{

	std::string url1 = "http://ivokovac.info ftp://www.centrum.sk";

	std::vector<std::string> web_content = find_urls(url1);
	for(std::vector<std::string>::iterator it = web_content.begin(); it != web_content.end(); it++)
		std::cout << *it;
	std::cout << std::endl;
	return 0;
}
