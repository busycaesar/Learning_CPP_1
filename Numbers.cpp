#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <fstream>
#include "Numbers.h"

using namespace std;

namespace sdds
{

	Numbers::Numbers()
	{

		setEmpty();
		this->m_isOriginal = false;

	}

	Numbers::Numbers(const char* filename)
	{

		setEmpty();
		this->m_isOriginal = true;
		setFilename(filename);
		this->m_numCount = numberCount();

		if (m_numCount == 0 || !load())
		{

			delete[] m_numbers;
			delete[] m_filename;

			this->m_numbers = nullptr;
			this->m_filename = nullptr;

			setEmpty();
			this->m_isOriginal = false;

		}
		else
		{

			sort();

		}

	}

	Numbers::Numbers(const Numbers& source)
	{

		setEmpty();
		this->m_isOriginal = false;

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

			this->m_numCount = source.m_numCount;

			this->m_filename = new char[strlen(source.m_filename) + 1];
			strcpy(this->m_filename, source.m_filename);

			this->m_numbers = new double[m_numCount];
			this->m_numbers = source.m_numbers;

		}

		return *this;

	}

	Numbers& Numbers::operator+=(const double newNum)
	{

		// VARIABLE DECLARATION.
		double* temp = new double[m_numCount+1];

		if (!isEmpty())
		{

			for (int i = 0; i < m_numCount; i++)
			{

				temp[i] = m_numbers[i];

			}

			temp[m_numCount] = newNum;
			m_numCount++;

			delete[] m_numbers;
			m_numbers = nullptr;
			m_numbers = new double[m_numCount];

			for (int i = 0; i < m_numCount; i++)
			{

				m_numbers[i] = temp[i];

			}

			delete[] temp;
			temp = nullptr;

			sort();

			for (int i = 0; i < m_numCount; i++)
			{
				cout << m_numbers[i]<<endl;
			}

		}
		else
		{

			cout << "Object is in Empty state." << endl;

		}

		return *this;


	}

	Numbers::~Numbers()
	{

		save();

		delete[] m_numbers;
		delete[] m_filename;

		this->m_numbers = nullptr;
		this->m_filename = nullptr;

	}

	bool Numbers::isEmpty() const
	{

		return m_numbers == nullptr;

	}

	void Numbers::setEmpty()
	{

		delete[] m_numbers;
		delete[] m_filename;

		this->m_numbers = nullptr;
		this->m_filename = nullptr;
		this->m_numCount = 0;

	}

	void Numbers::setFilename(const char* filename)
	{

		delete[] m_filename;
		this->m_filename = nullptr;

		this->m_filename = new char[strlen(filename) + 1];
		strcpy(m_filename, filename);
	}

	void Numbers::sort()
	{

		// VARIABLE DECLARATION.
		int i, j;
		double temp;

		for (i = this->m_numCount - 1; i > 0; i--)
		{

			for (j = 0; j < i; j++)
			{

				if (this->m_numbers[j] > this->m_numbers[j + 1])
				{

					temp = this->m_numbers[j];
					this->m_numbers[j] = this->m_numbers[j + 1];
					this->m_numbers[j + 1] = temp;

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

				aver += m_numbers[i];
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

			minVal = this->m_numbers[0];

			for (int i = 1; i < this->m_numCount; i++)

				if (minVal > this->m_numbers[i]) minVal = this->m_numbers[i];

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

				ostr << "-------------------------" << endl << "Total of " << this->m_numCount << " number(s)" << endl << "Largest number: " << max() << endl << "Smallest number: " << min() << endl << "Average: " << average() << endl << "=========================";

			}

		}
		else
		{

			ostr << "Empty list" << endl;

		}

		return ostr;

	}

	double Numbers::max() const
	{

		// VARIABLE DECLARATION.
		double maxVal = 0.0;

		if (!isEmpty())
		{

			maxVal = this->m_numbers[0];

			for (int i = 1; i < this->m_numCount; i++)

				if (maxVal < this->m_numbers[i]) maxVal = this->m_numbers[i];

		}

		return maxVal;

	}

	int Numbers::numberCount() const
	{

		// VARIABLE DECLARATION.
		ifstream file(this->m_filename);
		int totalNumbs = 0;
		char ch = '\0';

		if (file.is_open())
		{

			while (file)
			{

				totalNumbs += (file.get() == '\n');

			}

		}
		else
		{

			cout << "The file is not open." << endl;

		}

		return totalNumbs;

	}

	bool Numbers::load()
	{

		// VARIABLE DECLARATION.
		double temp = 0.0;
		int i = 0;
		ifstream file(this->m_filename);

		if (m_numCount > 0)
		{

			this->m_numbers = new double[this->m_numCount];

			if (file.is_open())
			{

				while (file >> temp)
				{

					this->m_numbers[i++] = temp;

				}

			}

		}

		return i == this->m_numCount;

	}

	void Numbers::save()
	{

		// VARIABLE DECLARATION.
		ofstream file(m_filename);

		if (m_isOriginal && !isEmpty())
		{

			if (file.is_open())
			{

				for (int i = 0; i < this->m_numCount; i++)
				{

					file << this->m_numbers[i] << endl;

				}

			}

		}

	}

	ostream& operator<<(ostream& os, const Numbers& N)
	{

		N.display(os);

		return os;

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