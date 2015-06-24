// Write a program that will keep track of grades for several students at once. The
// program could keep two vectors in sync: The first should hold the student's names,
// and the second the final grades that can be computed as input is read. For now, you
// should assume a fixed number of homework grades. We'll see in §4.1.3/56 how to
// handle a variable number of grades intermixed with student names.
// input: student names put into vector
// input: student grades for every student put into another vector
// output: printing result for every student

#include <algorithm>
#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <string>
#include <vector>

using std::cin;             using std::sort;
using std::cout;            using std::streamsize;
using std::endl;            using std::string;
using std::setprecision;    using std::vector;

int main()
{
  vector<string> student_names;
  vector<double> student_grades;

  cout << "Program keeps track of final grades for several students at once." << endl;
  string name;

  // ask for and read the student names and put them into student_names vector
  // for each student ask to enter his/her grades, compute final grade and put it into student_grades vector
  cout << "Put your name here folowed by end-of-file (CTRL+D): " << endl;
  while (cin >> name) {
		student_names.push_back(name);
		
		// ask for and read the midterm and final grades and for the homework grades
    cout << "Student " << name << " please, input your grades now." << endl; 
		cout << "Enter first your midterm and final grades, then all your homework grades, followed by end-of-file: ";

		// let student enter his/her grades
		vector<double> temp_grades;
		double grade;
		cin.clear();
		while (cin >> grade)
			temp_grades.push_back(grade);

		if (temp_grades.size() == 0) {
			cout << endl << "You must enter your grades. Please try again." << endl;	
			return 1;
		}

		// compute the final grade from temp_grades vector and assign it to student_grades vector
		int j = 0;
		int sum = 0;
		double final_grade;
		while(j < temp_grades.size()){
 			sum += temp_grades[j];
			j++;
		}
		// compute final grade
	  final_grade = (0.2 * temp_grades[0]) + (0.4 * temp_grades[1]) + ((sum - temp_grades[0] - temp_grades[1]) / (temp_grades.size() - 2) );

		// put the final grade for particular student into vector of grades
	  student_grades.push_back(final_grade);

		// reset temporary variables to be usable for another student
		j = 0; sum = 0; final_grade = 0;
		cin.clear();	

		// prompt for another user data - name and grades
 		cout << "Put your name here folowed by end-of-file (CTRL+D): " << endl;
  }	

  // print the results
  cout << endl << "Student name\t\t\tFinal grade" << endl << endl;
  int i = 0;
  while(i < student_names.size()){
    cout << student_names[i] << "\t\t\t\t" << student_grades[i] << endl;
    i++;
  }

  return 0;
}
