// program for exercise 6-3 and 6-4 regarding initialization of vectors/containers
/* 
	What does this program fragment do?
	vector<int> u(10, 100);
	vector<int> v;
	copy(u.begin(), u.end(), v.begin());

	Write a program that contains this fragment, and compile and execute it
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// fill constructor
	vector<int> u(100, 100);
	vector<int> v(100);

	// print out the first vector
	for(vector<int>::iterator i = u.begin(); i != u.end(); ++i)
		cout << (*i) << " ";
	cout << endl;

	// copy the content of the first vector into the second one
	std::copy(u.begin(), u.end(), v.begin());
	
	// print out the second vector
	for(vector<int>::iterator j = u.begin(); j != u.end(); ++j)
		cout << (*j) << " ";
	cout << endl;
	
	// copy constructor
	vector<int> a(10, 888);
	vector<int> b(a);

	for(vector<int>::iterator i = a.begin(); i != a.end(); ++i)
		cout << (*i) << " ";
	cout << endl;

	for(vector<int>::iterator i = b.begin(); i != b.end(); ++i)
		cout << (*i) << " ";
	cout << endl;

	// fill constructor
	vector<int> c(10, 321);
	vector<int> d(c.begin(), c.end());

	for(vector<int>::iterator i = c.begin(); i != c.end(); ++i)
		cout << (*i) << " ";
	cout << endl;

	for(vector<int>::iterator i = d.begin(); i != d.end(); ++i)
		cout << (*i) << " ";
	cout << endl;

	return 0;
}
