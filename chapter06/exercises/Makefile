comparing_grade_schemes: Student_info.o grade.o median.o analysis.o classify.o
	g++ -o comparing_grading_schemes comparing_grading_schemes.c++ Student_info.o grade.o median.o analysis.o classify.o

Student_info.o: Student_info.c++ Student_info.h
	g++ -c Student_info.c++

grade.o: grade.c++ grade.h
	g++ -c grade.c++ grade.h

median.o: median.c++ median.h
	g++ -c median.c++ median.h

analysis.o: analysis.c++ analysis.h grade.c++ grade.h
	g++ -c analysis.c++ analysis.h grade.c++ grade.h

classify.o: classify.c++ classify.h
	g++ -c classify.c++ classify.h
