// generating sentences using grammar rules
#include <iostream>
#include <istream>
#include <vector>
#include <map>
#include <string>
#include "split.h"
#include <stdexcept>

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


	return 0;
}
