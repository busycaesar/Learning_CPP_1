/*
NAME        : DEV JIGISHKUMAR SHAH
COURSE      : OOP 244 NCC
STUDENT ID  : 131623217
MAIL ID     : djshah11@myseneca.ca
DESCRIPTION : WORKSHOP 2 PART 1

DECLARATION:
IN THE BELOW CODE, I HAVE READ(OVERLOAD FUNCTION)'S DEFINATION IN THE USERNAME SDDS. ALL OF
THE OTHER CODE WAS PROVIDED TO ME BY THE FACULTY.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<iostream>
#include "File.h"

using namespace std;

namespace sdds
{

	// VARIABLE DECLARATION
	FILE* fptr = NULL;

	// FUNCTION DEFINITIONS

	// 1.
	bool openFile(const char filename[])
	{

		fptr = fopen(filename, "r");

		return fptr != NULL;

	}

	// 2.
	int noOfRecords()
	{

		int noOfRecs = 0;
		char ch;

		while (fscanf(fptr, "%c", &ch) == 1)
		{

			noOfRecs += (ch == '\n');

		}

		rewind(fptr);

		return noOfRecs;

	}

	// 3.
	void closeFile()
	{

		if (fptr)
		{
			fclose(fptr);
		}

	}

	// 4.
	bool read(char studentName[])
	{

		// VARIABLE DECLARATION
		bool alreadyRead = false;

		// THIS WILL STORE THE STUDENT NAME, STUDENT NUMBER AND STUDENT GRADE IN THEIR RESPECTIVE VARIABLES.
		if (fscanf(fptr, "%[^,],", studentName) == 1)
		{

			// THIS WILL RETURN TRUE IF THE DATA IS SUCCESSFULLY STORED.
			alreadyRead = true;

		}

		return alreadyRead;

	}

	// 4. 
	bool read(int& studentNumber)
	{

		// VARIABLE DECLARATION
		bool alreadyRead = false;

		if (fscanf(fptr, "%d,", &studentNumber) == 1)
		{

			// THIS WILL RETURN TRUE IF THE DATA IS SUCCESSFULLY STORED.
			alreadyRead = true;

		}

		return alreadyRead;

	}

	// 4. 
	bool read(char& studentGrade)
	{

		// VARIABLE DECLARATION
		bool alreadyRead = false;

		if (fscanf(fptr, "%c\n", &studentGrade) == 1)
		{

			// THIS WILL RETURN TRUE IF THE DATA IS SUCCESSFULLY STORED.
			alreadyRead = true;

		}

		return alreadyRead;

	}

}