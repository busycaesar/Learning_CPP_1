/*
NAME        : DEV JIGISHKUMAR SHAH
COURSE      : OOP 244 NCC
STUDENT ID  : 131623217
MAIL ID     : djshah11@myseneca.ca
DESCRIPTION : WORKSHOP 2 PART 1

DECLARATION:
IN THE BELOW CODE, I HAVE READ(OVERLOAD FUNCTION)'S PROTOTYPE IN THE USERNAME SDDS. ALL OF
THE OTHER CODE WAS PROVIDED TO ME BY THE FACULTY.
*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

using namespace std;

namespace sdds
{

	// FUNCTIONS PROTOTYPES

	bool openFile(const char filename[]);

	void closeFile();

	int noOfRecords();

	bool read(char studentName[]);
	bool read(int& studentNumber);
	bool read(char& studentGrade);

}

#endif // !SDDS_FILE_H_
