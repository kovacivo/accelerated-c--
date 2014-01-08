// ask for a person's name and generate a framed greeting
#include <iostream>
#include <string>

// say what standard-library names we use
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	// ask for person's name
	cout << "Please enter your first name: ";

	// read the name
	string name;
	cin >> name;

	// build the message that we intend to write
	const string greeting = "Hello, " + name + "!";

	// the number of blanks surronding the greeting
	// ask user for padding
	const int pad = 1;

	// total number of rows to write
	const int rows = pad * 4 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;
	const string asterisks(cols,'*');
	const string blanks(greeting.size() + pad * 2,' ');

	// separate the output from the input
	std::cout << std::endl;

	// write rows of output
	// invariant: we have written r rows so far
	for (int r = 0; r < rows; ++r) {

		// je to prvy alebo posledny riadok/rad???
		if (r == 0 || r == rows-1)
			cout << asterisks << endl;
		else {
			// prazdny riadok
			// pocet riadkov deleno dvomi - rata sa od nuly
			if (r != rows/2) 
				cout << "*" + blanks + "*" << endl;
			// tlacim pozdrav
			else
				cout << "* " +  greeting + " *" << endl;
		}

//		cout << "R is " << r << endl;
	}

	cout << endl;

	return 0;
}
