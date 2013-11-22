/* 
	program/function finds web addresses (URLs) that are embedded in a string

	the function scans the document (stored in a string) and find all the URLs in it
	a URL is a sequence of characters of the form: protocol-name://resource-name
	where protocol-name contains only letters
	and resource-name contains only letters, digits and certain punctuation characters
	the function will take a string argument and will look for instances of :// in that string
	each time such an instance will be found, we'll look for the protocol-name that precedes it and resource-name that follows it
	we want our function to find all the URLs in its input, it will return a vector<string> with one element for each URL
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype>

std::vector<std::string> find_urls(std::string& s)
{
	// vector to return
	std::vector<std::string> vec;

	std::string::iterator beg = s.begin();
	std::string::iterator it = beg;
	std::string::iterator end = s.end();
	std::string search_seq = "://";

	while ((beg != end))
	{
	
		// get rid of the spaces at the beginning
		if (isspace(*beg))
		{
			beg++;
			continue;
		}
	
		// perform a search
		it = std::search(beg, end, search_seq.begin(), search_seq.end());

		// if there is no :// sequence, the search function will return the last element
		if (it == s.end())
			break;
		else
			{
				// make a URL
				std::string url(beg, it);
				
				// find the resource end - that is at the next space
				std::string::iterator resource_end = it+3;
				while ((isalnum(*resource_end)) || (ispunct(*resource_end)))
					++resource_end;

				// make a resource
				std::string resource((it+3),(resource_end));

				// jump behind the pair URL/resource at the next possible sequence
				beg = resource_end;

				// put the pair into a vector
				vec.push_back(std::string(url + " -> " + resource));
		}
		// update the beginning of searched string
		beg++;
	}

	// return ready vector
	return vec;
}

int main()
{

	std::string url1 = "   http://ivokovac.info";
	std::string url2 = "http://ivokovac.info ftp://www.centrum.sk file://localfile    mail://ivotiki";
	std::string input = "";

	std::cout << "Enter the web resources and acquire the URL -> resource name pairs." << std::endl;
	while (std::cin >> input)
	{
		std::vector<std::string> web_content = find_urls(input);
		for(std::vector<std::string>::iterator it = web_content.begin(); it != web_content.end(); it++)
			std::cout << *it << std::endl;;
	}
	std::cout << std::endl;
	return 0;
}
