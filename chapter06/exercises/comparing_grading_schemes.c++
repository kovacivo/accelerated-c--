#include <iostream>
#include <vector>
#include <algorithm>
#include "Student_info.h"
#include "analysis.h"
#include "median.h"
#include "grade.h"
#include "classify.h"

using namespace std;

void print_vector_Studentinfo(const vector<Student_info>& vec)
{
	for(vector<Student_info>::const_iterator i = vec.begin(); i != vec.end(); i++)
		cout << (*i).name << " " << (*i).final_grade << endl;
}

int main()
{

	vector<Student_info> did, didnt;
	Student_info student;

	// read all the records, separating them based on whether all homework was done
	while (read(cin,student))
	{
		if(did_all_hw(student))
		{
			cout << "Urobil: " + student.name << endl;
			did.push_back(student);
		}
		else
			{
				cout << "Neurobil: " + student.name << endl;
				didnt.push_back(student);
			}
	}


	// check that both groups contain data
	
	if (did.empty())
	{
		cout << "No student did all the homework!" << endl;
		return 1;
	}
	if (didnt.empty())
	{
		cout << "Every student did all the homework!" << endl;
		return 1;
	}


	// do the analysis
	write_analysis(cout,"median", median_analysis, did, didnt);
	write_analysis(cout,"average", average_analysis, did, didnt);
	write_analysis(cout,"optimistic median", optimistic_analysis, did, didnt);

	vector<Student_info> failed = extract_fails(did);
	print_vector_Studentinfo(failed);
	
	return 0;
}
