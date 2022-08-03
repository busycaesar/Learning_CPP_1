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
#include"BarChart.h"
#include"Bar.h"

using namespace std;

namespace sdds
{

	bool BarChart::isValid() const
	{

		// VARIABLE DECLARATION.
		bool success = true;

		for (int i = 0; i < m_noOfBars; i++)
		{

			if (!(m_bars[i].testValid()))
			{

				success = false;
				break;

			}

		}

		return success;

	}

	void BarChart::setEmpty()
	{

		m_noOfBars = 0;
		m_noOfSample = 0;

	}

	void BarChart::init(const char* title, int noOfSampels, char fill)
	{

		setEmpty();

		if (title != nullptr && noOfSampels != 0 && fill != '\0')
		{

			m_barChartTitle = new char[strlen(title) + 1];
			strcpy(m_barChartTitle, title);
			m_fillCharacter = fill;
			m_noOfBars = noOfSampels;
			m_bars = new Bar[m_noOfBars];

		}

	}

	void BarChart::add(const char* bar_title, int value)
	{

		if (m_noOfSample < m_noOfBars)
		{

			m_bars[m_noOfSample].set(bar_title, m_fillCharacter, value);
			m_noOfSample++;

		}

	}

	void BarChart::draw()const
	{

		// THE CHART WILL ONLY BE DISPLAYED IN CASE ALL THE VALUES ARE FILLED AND ARE VALID.
		if (isNotEmpty() && isValid())
		{

			// THIS WILL DISPLAY THE TITLE OF THE BAR CHART.
			cout << m_barChartTitle << endl;
			cout.fill('-');
			cout.width(71);
			cout << "-" << endl;

			// THIS WILL DISPLAY THE BARS.
			for (int i = 0; i < m_noOfBars; i++)
			{

				m_bars[i].draw();

			}

			cout.fill('-');
			cout.width(71);
			cout << "-" << endl;

		}
		else
		{

			cout << "Invalid Chart!" << endl;

		}

	}

	void BarChart::deallocate()
	{

		delete[] m_barChartTitle;
		delete[] m_bars;
		m_barChartTitle = nullptr;
		m_bars = nullptr;

	}

	bool BarChart::isNotEmpty()const
	{

		return (m_noOfBars == m_noOfSample);

	}

}