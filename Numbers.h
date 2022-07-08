#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_

#include<iostream>

using namespace std;

namespace sdds
{

	// CLASSES.
	class Numbers
	{

		// DATA VARIABLES.
		double* m_numbers;
		char* m_filename;
		bool m_isOriginal;
		int m_numCount;

		// PRIVATE FUNCTIONS.
		bool isEmpty()const;
		void setEmpty();
		void setFilename(const char* filename);
		void sort();
		int numberCount()const;
		bool load();
		void save();

	public:

		// CONSTRUCTORS.
		Numbers();
		Numbers(const char* filename);
		Numbers(const Numbers& source);

		// OPERATORS.
		Numbers& operator=(const Numbers& source);
		Numbers& operator+=(const double newNum);

		// PUBLIC FUNCTIONS.
		double average()const;
		double max()const;
		double min()const;
		ostream& display(ostream& ostr) const;

		// DESTRUCTOR.
		~Numbers();

	};

	ostream& operator<<(ostream& os, const Numbers& N);
	istream& operator>>(istream& istr, Numbers& N);

}

#endif // !SDDS_NUMBERS_H_
