#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::ostream;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::list;
using std::max;

int main()

{	list<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// ask for and read the student's name
	// ask for and read the midterm and final grades
	cout << "Please enter your first name, enter your midterm and final exam grades, your homework grades. " <<  endl;

	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	//sort(students.begin(), students.end(), compare);

    /* 
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		// compute and generate the final grade, if possible
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << "Your final grade is " << setprecision(3)
		     << final_grade << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what();
		}
	
		cout << endl;
	}
	*/

	list<Student_info> failed = extract_fails_v4(students);
	cout << "Here are the passed students." << endl;
	list<Student_info>::iterator iter = students.begin();
	while(iter != students.end())
	{
		cout << (*iter).name << string(maxlen + 1 - (*iter).name.size(), ' ');

		// compute and generate the final grade, if possible
		try {
			// double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << "Your final grade is " << setprecision(3)
		     // << final_grade << setprecision(prec);
		     << (*iter).final_grade << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}
	
		cout << endl;
		iter++;
	}

	
	cout << endl;

	cout << "Here are the failed students." << endl;
	iter = failed.begin();
	while(iter != failed.end())
	{
		cout << (*iter).name << string(maxlen + 1 - (*iter).name.size(), ' ');

		// compute and generate the final grade, if possible
		try {
			// double final_grade = grade(failed[i]);
			streamsize prec = cout.precision();
			cout << "Your final grade is " << setprecision(3)
		     << (*iter).final_grade << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}
	
		cout << endl;
		iter++;
	}
    

	return 0;
}
