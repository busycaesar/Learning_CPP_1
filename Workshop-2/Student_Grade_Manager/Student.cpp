/*
NAME        : DEV JIGISHKUMAR SHAH
COURSE      : OOP 244 NCC
STUDENT ID  : 131623217
MAIL ID     : djshah11@myseneca.ca
DESCRIPTION : WORKSHOP 2 PART 1

DECLARATION:
IN THE BELOW CODE, I HAVE DECLARED VARIABLES, AND CREATED LOAD(OVERLOAD FUNCTION), DISPLAY
(OVERLOAD FUNCTION) AND DEALLOCATEMEMORY FUNCTION'S DEFINATION IN THE USERNAME SDDS. ALL OF
THE OTHER CODE WAS PROVIDED TO ME BY THE FACULTY.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include<iostream>
#include<cstring>
#include"Student.h"
#include"File.h"

using namespace std;

namespace sdds
{

	// VARIABLE DECLARATION.
	int noOfStudents;
	Student* students = nullptr;

	// FUNCTION DEFINITATIONS.

	void sort()
	{

		// VARIABLE DECLARATION.
		int i, j;
		Student temp;

		for (i = noOfStudents - 1; i > 0; i--)
		{

			for (j = 0; j < i; j++)
			{

				if (students[j].m_grade > students[j + 1].m_grade)
				{

					temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;

				}
			}

		}
	}

	bool load(Student& studentLoad)
	{

		// VARIABLE DECLARATION.
		char studentName[128];
		bool successRead = false;
		int nameLength, determineReturn[3];

		// THIS WILL READ THE STUDENT NAME FROM THE FILE AND COUNT ITS LENGTH.
		successRead = read(studentName);

		if (successRead)
		{

			determineReturn[0] = 1;

			nameLength = strlen(studentName);

			// THIS WILL ALLOCATE DYNAMIC MEMORY TO THE ARRAY OF NAME CHARACTERS.
			studentLoad.m_name = nullptr;
			studentLoad.m_name = new char[nameLength + 1];

			// THIS WILL COPY THE NAME OF THE STUDENT FROM THE LOCAL ARRAY TO THE STRUCT ARRAY.
			strcpy(studentLoad.m_name, studentName);

		}

		// THIS WILL READ THE STUDENT NUMBER FROM THE FILE.
		successRead = read(studentLoad.m_studentNumber);
		determineReturn[1] = successRead;

		// THIS WILL READ THE GRADE OF STUDENT FROM THE FILE.
		successRead = read(studentLoad.m_grade);
		determineReturn[2] = successRead;

		// IF ALL THE THREE READS ARE SUCCESSFULL, THE FUNCTION WILL RETURN TRUE.
		if (determineReturn[0] && determineReturn[1] && determineReturn[2])
		{

			successRead = true;

		}

		else
		{

			successRead = false;

		}

		return successRead;

	}

	bool load(const char filename[])
	{

		int success = 0;

		success = openFile(filename);

		if (success)
		{

			noOfStudents = noOfRecords();
			students = new Student[noOfStudents + 1];

			// THIS WILL LOAD THE INFORMATION OF ALL THE STUDENTS ONE BY ONE IN THE ARRAY OF STUDENTS.
			for (int i = 0; i < noOfStudents; i++)
			{

				load(students[i]);

			}

		}

		return true;

	}

	void display(const Student& temp, int a)
	{

		cout << a << ": " << temp.m_name << ", " << temp.m_studentNumber << ": " << temp.m_grade << endl;

	}

	void display()
	{

		sort();

		for (int i = 0; i < noOfStudents; i++)
		{

			display(students[i], i + 1);

		}

		closeFile();

	}

	void deallocateMemory()
	{

		for (int i = 0; i < noOfStudents; i++)
		{

			delete[] students[i].m_name;
			students[i].m_name = nullptr;

		}

		delete[] students;
		students = nullptr;

	}

}