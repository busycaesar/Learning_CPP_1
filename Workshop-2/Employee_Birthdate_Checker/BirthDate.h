/*
* NAME        : DEV JIGISHKUMAR SHAH
* COURSE      : OOP 244 NCC
* STUDENT ID  : 131623217
* MAIL ID     : djshah11@myseneca.ca
* SUBMISSION  : WORKSHOP 2 PART 2
* DECLARATION : THIS ENTIRE MODULE IS WRITTEN BY ME EXCEPT THE NAME OF SOME FUNCTIONS
*               AND THEIR PARAMETERS WHICH WERE PROVIDED TO ME BY THE FACULTY.
*/

#ifndef SDDS_BIRTHDATE_H 
#define SDDS_BIRTHDATE_H

namespace sdds
{
	// STRUCTS

	// THIS STRUCT WILL STORE THE DETAILS PER EMPLOYEE. 
	struct Employees
	{

		// VARIABLE DECLARATION.
		char* m_name;
		int m_birthYear, m_birthMonth, m_birthDate;

	};

	// FUNCTION PROTOTYPES

	bool beginSearch(const char* filename);
	bool readBirthDate(int month);
	void sort();
	void displayBirthdays();
	void deallocate();
	void endSearch();

	// THESE FUNCTIONS WILL READ THE DATA FROM THE FILE.
	bool readData(char* empName, int& month, int& date, int& year);

	// THIS FUNCTION WILL COUNT THE TOTAL LINES OF DATA IN THE FILE.
	int totalEmployees();

	// THIS FUNCTION WILL ASSIGN THE REQUIRED DATA IN THE ARRAY.
	void assignData(int month);

}

#endif