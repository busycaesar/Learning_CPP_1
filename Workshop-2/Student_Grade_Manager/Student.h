/*
NAME        : DEV JIGISHKUMAR SHAH
COURSE      : OOP 244 NCC
STUDENT ID  : 131623217
MAIL ID     : djshah11@myseneca.ca
DESCRIPTION : WORKSHOP 2 PART 1

DECLARATION:
IN THE BELOW CODE, I HAVE CREATED LOAD(OVERLOAD FUNCTION), DISPLAY
(OVERLOAD FUNCTION) AND DEALLOCATEMEMORY FUNCTION'S PROTOTYPES IN THE USERNAME SDDS. ALL OF
THE OTHER CODE WAS PROVIDED TO ME BY THE FACULTY.
*/

#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include"File.h"

namespace sdds
{

	// STRUCTS
	struct Student {

		// VARIABLE DECLARATION.
		char* m_name;
		int m_studentNumber;
		char m_grade;

	};

	// FUNCTION PROTOTYPES.

	void sort();

	bool load(Student& student);
	bool load(const char filename[]);

	void display(const Student& temp, int a);
	void display();

	void deallocateMemory();

}

#endif