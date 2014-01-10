// generating sentences using grammar rules
#include <iostream>
#include <istream>
#include <vector>
#include <map>
#include <string>
#include "split.h"
#include <stdexcept>
#include <cstdlib>

typedef std::vector<std::string> Rule;
typedef	std::vector<Rule> Rules_collection;
typedef std::map<std::string, Rules_collection> Grammar;

// read grammar from input
Grammar read_grammar(std::istream& in)
{
	Grammar output;
	std::string line;
		
	// read input
	while (std::getline(in, line))
	{

		// function split splits the input into the words
		std::vector<std::string> record = split(line);
		
		if(!record.empty())
			output[record[0]].push_back(Rule(record.begin() + 1, record.end()));
	}

	return output;
}

bool inbracketes(const std::string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() -1] == '>';
}

int random_num(int n)
{
	std::cout << "in random_num function the number n is: " << n << std::endl;
	int random_number = 0;
	if (n <= 0 || n > RAND_MAX)
		throw std::domain_error("Argument to random_num is out of range");

	const int bucket_size = RAND_MAX / n;
	int r;

	do r = rand() / bucket_size;
	while (r >= n);

	return r;
}

void gen_help(const Grammar& g, const std::string& word, std::vector<std::string>& ret)
{
	if (!inbracketes(word))
	{
		ret.push_back(word);
	} else {
		// find a rule corresponding to the content of 'word'
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw std::logic_error("empty rule");

		// get the set of possible rules
		const Rules_collection& rule_col = it->second;

		// from which it randomly chooses one
		const Rule& r = rule_col[random_num(rule_col.size())];

		// recursively develop choosen rule
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_help(g, *i, ret);
	}
}

std::vector<std::string> generate_sentence(const Grammar& g)
{
	std::vector<std::string> ret;
	gen_help(g, "<sentence>", ret);
	return ret;
}

int main()
{

	// generate the sentence
	std::vector<std::string> sentence = generate_sentence(read_grammar(std::cin));

	// write the first word, if any
	std::vector<std::string>::const_iterator it = sentence.begin();
	if (!sentence.empty()) {
		std::cout << *it;
		++it;
	}

	// write the rest of the words preceded by a space
	while (it != sentence.end()) {
		std::cout << " " << *it;
		++it;
	}

	std::cout << std::endl;

	return 0;
}
