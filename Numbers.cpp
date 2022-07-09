#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional

using namespace std;

namespace sdds
{

	Numbers::Numbers()
	{

		setEmpty();
		m_isOriginal = false;

	}

	Numbers::Numbers(const char* filename)
	{

		setEmpty();
		m_isOriginal = true;
		setFilename(filename);
		m_numCount = numberCount();

		if (m_numCount == 0 || !load())
		{

			delete[] m_numbers;
			delete[] m_filename;

			setEmpty();
			m_isOriginal = false;

		}
		else
		{

			sort();

		}

	}

	Numbers::Numbers(const Numbers& source)
	{

		setEmpty();
		m_isOriginal = false;

		*this = source;

	}

	Numbers& Numbers::operator=(const Numbers& source)
	{

		if (this != &source)
		{

			delete[] m_numbers;
			delete[] m_filename;

			m_numbers = nullptr;
			m_filename = nullptr;

			m_numCount = source.m_numCount;

			m_filename = new char[strlen(source.m_filename) + 1];
			strcpy(m_filename, source.m_filename);

			m_numbers = new double[m_numCount];

			for (int i = 0; i < m_numCount; i++)
			{

				m_numbers[i] = source.m_numbers[i];

			}

		}

		return *this;

	}

	Numbers& Numbers::operator+=(double newNum)
	{

		if (!isEmpty())
		{

			// VARIABLE DECLARATION.
			double* temp = new double[m_numCount + 1];

			for (int i = 0; i < m_numCount; i++)
			{

				temp[i] = m_numbers[i];

			}

			temp[m_numCount] = newNum;
			m_numCount++;

			delete[] m_numbers;
			m_numbers = nullptr;

			m_numbers = temp;

			temp = nullptr;

			sort();

		}

		return *this;

	}

	Numbers::~Numbers()
	{

		save();

		delete[] m_numbers;
		delete[] m_filename;

	}

	bool Numbers::isEmpty() const
	{

		return m_numbers == nullptr;

	}

	void Numbers::setEmpty()
	{

		m_numbers = nullptr;
		m_filename = nullptr;
		m_numCount = 0;

	}

	void Numbers::setFilename(const char* filename)
	{

		delete[] m_filename;

		m_filename = new char[strlen(filename) + 1];
		strcpy(m_filename, filename);

	}

	void Numbers::sort()
	{

		// VARIABLE DECLARATION.
		int i, j;
		double temp;

		for (i = m_numCount - 1; i > 0; i--)
		{

			for (j = 0; j < i; j++)
			{

				if (m_numbers[j] > m_numbers[j + 1])
				{

					temp = m_numbers[j];
					m_numbers[j] = m_numbers[j + 1];
					m_numbers[j + 1] = temp;

				}

			}

		}

	}

	double Numbers::average() const
	{

		// VARIABLE DECLARATION.
		double aver = 0.0;

		if (!isEmpty())
		{

			for (int i = 0; i < m_numCount; i++)
			{

				aver += m_numbers[i];

			}

			aver = aver / m_numCount;

		}

		return aver;

	}

	double Numbers::min() const
	{

		// VARIABLE DECLARATION.
		double minVal = 0.0;

		if (!isEmpty())
		{

			minVal = m_numbers[0];

			for (int i = 1; i < m_numCount; i++)
			{

				if (minVal > m_numbers[i])
				{

					minVal = m_numbers[i];

				}

			}

		}

		return minVal;

	}

	ostream& Numbers::display(ostream& ostr)const
	{

		if (!isEmpty())
		{

			ostr << "=========================" << endl;

			if (this->m_isOriginal)
			{

				ostr << this->m_filename << endl;

			}
			else
			{

				ostr << "*** COPY ***" << endl;

			}

			for (int i = 0; i < this->m_numCount; i++)
			{

				ostr << this->m_numbers[i];

				if (i == (this->m_numCount - 1))
				{

					ostr << endl;

				}
				else
				{

					ostr << ", ";

				}

			}

			ostr << "-------------------------" << endl << "Total of " << m_numCount << " number(s)" << endl;
			ostr.width(17);
			ostr << left << "Largest number:";
			ostr << max() << endl;
			ostr.width(17);
			ostr << left << "Smallest number:" << min() << endl;
			ostr.width(17);
			ostr << left << "Average :" << average() << endl << "=========================";

		}
		else
		{

			ostr << "Empty list";

		}

		return ostr;

	}

	double Numbers::max() const
	{

		// VARIABLE DECLARATION.
		double maxVal = 0.0;

		if (!isEmpty())
		{

			maxVal = m_numbers[0];

			for (int i = 1; i < this->m_numCount; i++)
			{

				if (maxVal < m_numbers[i])
				{

					maxVal = m_numbers[i];

				}

			}

		}

		return maxVal;

	}

	int Numbers::numberCount() const
	{

		// VARIABLE DECLARATION.
		ifstream file(m_filename);
		int totalNumbs = 0;

		if (file.is_open())
		{

			while (file)
			{

				totalNumbs += (file.get() == '\n');

			}

		}

		return totalNumbs;

	}

	bool Numbers::load()
	{

		// VARIABLE DECLARATION.
		double temp = 0.0;
		int i = 0;
		ifstream file(m_filename);

		if (m_numCount > 0)
		{

			m_numbers = new double[m_numCount];

			if (file.is_open())
			{

				while (file >> temp)
				{

					m_numbers[i] = temp;
					i++;

				}

			}

		}

		return i == m_numCount;

	}

	void Numbers::save()
	{

		if (m_isOriginal && !isEmpty())
		{

			// VARIABLE DECLARATION.
			ofstream file(m_filename);

			if (file.is_open())
			{

				for (int i = 0; i < m_numCount; i++)
				{

					file << m_numbers[i] << endl;

				}

			}

		}

	}

	ostream& operator<<(ostream& os, const Numbers& N)
	{

		return N.display(os);

	}

	istream& operator>>(istream& istr, Numbers& N)
	{

		// VARIABLE DECLARATION.
		double temp = 0.0;

		istr >> temp;
		N += temp;

		return istr;

	}

}