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

#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H

#include"Bar.h"

namespace sdds
{

	class BarChart
	{

		// MEMBER VARIABLES.
		char* m_barChartTitle = nullptr;
		Bar* m_bars = nullptr;
		char m_fillCharacter;
		int m_noOfBars;
		int m_noOfSample;

	public:

		// MEMBER FUNCTIONS.
		bool isValid() const;
		void setEmpty();
		void init(const char* title, int noOfSampels, char fill);
		void add(const char* bar_title, int value);
		void draw()const;
		void deallocate();
		bool isNotEmpty()const;

	};

}

#endif // !SDDS_BARCHART_H
