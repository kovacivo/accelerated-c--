5-0: Student_info.o grade.o median.o
	g++ -o 5-0 5-0.c++ Student_info.o grade.o median.o

5-0-a: Student_info.o grade.o median.o
	g++ -o 5-0-a 5-0-a.c++ Student_info.o grade.o median.o

5-0-b: Student_info.o grade.o median.o
	g++ -o 5-0-b 5-0-b.c++ Student_info.o grade.o median.o

5-0-c: Student_info.o grade.o median.o
	g++ -o 5-0-c 5-0-c.c++ Student_info.o grade.o median.o

Student_info.o: Student_info.c++ Student_info.h
	g++ -c Student_info.c++

grade.o: grade.c++ grade.h
	g++ -c grade.c++ grade.h

median.o: median.c++ median.h
	g++ -c median.c++ median.h

clean:
	rm 5-0  5-0-a 5-0-b 5-0-c *.o
