/*
* NAME        : DEV JIGISHKUMAR SHAH
* COURSE      : OOP 244 NCC
* STUDENT ID  : 131623217
* MAIL ID     : djshah11@myseneca.ca
* SUBMISSION  : WORKSHOP 2 PART 2
* DECLARATION : THIS ENTIRE MODULE IS WRITTEN BY ME EXCEPT THE NAME OF SOME FUNCTIONS
*               AND THEIR PARAMETERS WHICH WERE PROVIDED TO ME BY THE FACULTY.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include<iostream>
#include<cstring>
#include"BirthDate.h"

using namespace std;

namespace sdds
{

	// VARIABLE DECLARATION.
	FILE* EmpData = NULL;
	Employees* employeeData = nullptr;
	int totalData = 0, bdayEmps = 0;

	// FUNCTION DEFINATION.

	// THIS FUNCTION WILL SEARCH IF THE FILE ENTERED BY THE USER EXISTS IN THE FOLDER OR NOT. IF IT DOES, IT WILL OPEN
	// THAT FILE IN READ MODE.
	bool beginSearch(const char* filename)
	{

		// VARIABLE DECLARATION.
		bool success = false;
		EmpData = fopen(filename, "r");

		// THIS WILL VERIFY IF THE FILE EXISTS OR NOT. IF IT DOES, IT IS OPENED OR NOT.
		if (EmpData != NULL)
		{

			// IF THE FILE EXISTS AND IS OPENED, THIS FUNCTION WILL RETURN TRUE.
			success = true;

			cout << "Birthdate search program" << endl;

		}
		else
		{

			cout << "Data file " << filename << " not found!";

		}

		return success;

	}

	bool readBirthDate(int month)
	{

		// VARIABLE DECLARATION.
		bool success = false;

		totalData = totalEmployees();

		// DYNAMIC MEMORY ALLOCATION.
		employeeData = new Employees[totalData];

		for (int i = 0; i < totalData; i++)
		{

			assignData(month);
			success = true;

		}

		return success;

	}

	void sort()
	{

		// VARIABLE DECLARATION.
		int i, j;
		Employees temp;

		for (i = bdayEmps - 1; i > 0; i--)
		{

			for (j = 0; j < i; j++)
			{

				if (employeeData[j].m_birthYear > employeeData[j + 1].m_birthYear)
				{

					temp = employeeData[j];
					employeeData[j] = employeeData[j + 1];
					employeeData[j + 1] = temp;

				}
			}

		}

	}

	void displayBirthdays()
	{

		cout << bdayEmps << " birthdates found:" << endl;

		for (int i = 0; i < bdayEmps; i++)
		{

			cout << i + 1 << ") " << employeeData[i].m_name << ":" << endl;
			cout << employeeData[i].m_birthYear << "-" << employeeData[i].m_birthMonth << "-" << employeeData[i].m_birthDate << endl;
			cout << "===================================" << endl;

		}

	}

	void deallocate()
	{
		for (int i = 0; i < bdayEmps; i++)
		{
			delete[] employeeData[i].m_name;
		}

		delete[] employeeData;

	}

	void endSearch()
	{

		fclose(EmpData);

	}

	void assignData(int month)
	{

		// VARIABLE DECLARATION.
		char empName[31];
		bool readSuccess = false;
		int empYear = 0, empMonth = 0, empDate = 0;

		readSuccess = readData(empName, empMonth, empDate, empYear);

		if (readSuccess)
		{

			if (empMonth == month)
			{

				// DYNAMIC MEMORY ALLOCATION.
				employeeData[bdayEmps].m_name = nullptr;
				employeeData[bdayEmps].m_name = new char[strlen(empName) + 1];

				strcpy(employeeData[bdayEmps].m_name, empName);
				employeeData[bdayEmps].m_birthDate = empDate;
				employeeData[bdayEmps].m_birthMonth = empMonth;
				employeeData[bdayEmps].m_birthYear = empYear;

				bdayEmps++;

			}

		}

	}

	bool readData(char* empName, int& month, int& date, int& year)
	{

		// VARIABLE DECLARATION.
		bool success = false;

		if (fscanf(EmpData, "%[^,],%d/%d/%d\n", empName, &month, &date, &year) == 4)
		{

			success = true;

		}

		return success;

	}

	// THIS FUNCTION WILL COUNT THE TOTAL NUMBER OF EMPLOYEES WHO HAS BIRTHDATE IN THAT MONTH.
	int totalEmployees()
	{

		int noOfRecs = 0;
		char ch;

		while (fscanf(EmpData, "%c", &ch) == 1)
		{

			noOfRecs += (ch == '\n');

		}

		rewind(EmpData);

		return noOfRecs;

	}

}