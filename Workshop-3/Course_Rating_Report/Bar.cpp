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

#define _CRT_SECURE_NO_WARNINGS

#include<cstring>
#include<iostream>
#include"Bar.h"

using namespace std;

namespace sdds
{

	void Bar::setEmpty()
	{

		// VARIABLE DECLARATION.
		m_titleOfBar[0] = '\0';
		m_fillCharacter = '\0';
		m_sample = 0;

	}

	void Bar::set(const char* title, char fillCharacter, int value)
	{

		// THIS WILL FIRST SET ALL THE VARIABLES EMPTY.
		setEmpty();

		// THIS WILL CONFIRM THAT THE VALUE IS APPROPRIATE.
		if (validBar(value) && title[0] != '\0' && strlen(title) < 20)
		{

			strcpy(m_titleOfBar, title);
			m_fillCharacter = fillCharacter;
			m_sample = value;

		}

	}

	bool Bar::testValid() const
	{

		return (m_titleOfBar != nullptr && m_fillCharacter != '\0' && m_sample != 0);

	}

	void Bar::draw() const
	{

		if (validBar(m_sample))
		{

			// THIS WILL FIRST PRINT THE STRING WHICH WE WANT TO DISPLAY AND LATER ON WILL FILL THE REMAINING SPACE SPECIFIED THROUGH THE 'WIDTH', USING THE CHARACTER SPECIFIED THROUGH 'FILL'.
			cout.fill('.');
			cout.width(20);
			cout << left << m_titleOfBar;
			cout << "|";

			//THIS WILL PRINT THE STRING WHICH WE WANT TO DISPLAY; HOWEVER, BEFORE THAT THIS WILL FILL THE REMAINING SPACE SPECIFIED THROUGH THE 'WIDTH', USING THE CHARACTER SPECIFIED THROUGH 'FILL'.
			cout.fill(m_fillCharacter);
			cout.width(int(m_sample / 2));
			cout << m_fillCharacter << endl;

		}

	}

	bool Bar::validBar(int value) const
	{

		return ((value > 0) && (value <= 100));

	}

}