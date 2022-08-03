/**************************************************************************************************************************
* NAME        : DEV JIGISHKUMAR SHAH
* COURSE      : OOP 244 NCC
* MAIL ID     : djshah11@myseneca.ca
* STUDENT ID  : 131623217
* SUBMISSION  : WORKSHOP 3 PART 2
* DECLARATION : THIS IS TO DECLARE THAT THE WHOLE PROGRAM WRITTEN BELOW IS COMPELTELY MY OWN CREATION. I JUST HAVE
*               READ THE DOCUMENTATION PROVIDED BY THE SCHOOL ON GITHUB AND FOLLOWED THE INSTRUCTIONS WHICH THEY SUGGESTED.
*               OTHER THAN THAT, I HAVE NOT COPIED OR SOUGHT HELP FROM ANY OF MY CLASSMATE OR SENIOR.
**************************************************************************************************************************/

#ifndef SDDS_BAR_H
#define SDDS_BAR_H

namespace sdds
{

	const int MAX_TITLE = 20;

	// DECLARING CLASS.
	class Bar
	{

		char m_titleOfBar[MAX_TITLE];
		char m_fillCharacter;
		int m_sample;

	public:

		// MEMBER FUNCTIONS.
		void setEmpty();
		void set(const char* title, char fillCharacter, int value);
		bool testValid() const;
		void draw() const;
		bool validBar(int value) const;

	};

}

#endif // !SDDS_BAR_H
