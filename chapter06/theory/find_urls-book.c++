#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!&'(),";

	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}


std::string::const_iterator url_beg(std::string::const_iterator& b, std::string::const_iterator& e)
{
	static const string sep = "://";

	typedef string::const_iterator iter;

	// i marks where the separator was found
	iter i = b;

	while((i = search(i, e, sep.begin(), sep.end())) != e)
	{
		// make sure the separator isn't at the beginning or end of the line
		if (i != b && i + sep.size() != e)
		{
			// beg marks the beginning of the protocol-name
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))
				--beg;

			// is there at least one appropriate character before and after the sep
			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}

		// the separator we found was not part of a URL advance i past this separator
		i += sep.size();
	}
	return e;
}

std::string::const_iterator url_end(std::string::const_iterator& b, std::string::const_iterator& e)
{
	return find_if(b, e, not_url_char);
}

std::vector<std::string> find_urls(const std::string& s)
{
	std::vector<std::string> ret;
	typedef std::string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	// look through the entire input
	while (b != e)
	{
		// look for one or more letters followed by ://
		b = url_beg(b, e);

		// if we found it
		if (b != e)
		{
			// get the rest of the URL
			iter after = url_end(b, e);

			// remember the URL
			ret.push_back(std::string(b, after));

			// advance b and check for more URLs on this line
			b = after;
		}
	}
	
	return ret;
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

