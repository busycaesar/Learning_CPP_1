#define _CRT_SECURE_NO_WARNINGS

#include"Minister.h"
#include<iostream>

using namespace std;

namespace sdds
{

	void Minister::setEmpty()
	{

		m_pmName[0] = '\0';
		m_year = 0000;

	}

	Minister::Minister(const char* id, int age, int year, const char* district, char pmName[])
	{

		setEmpty();

		MemberParliament::NewDistrict(district);
		m_year = year;
		strcpy(m_pmName, pmName);

	}

	void Minister::changePM(const char* pm)
	{

		strcpy(m_pmName, pm);

	}

	void Minister::assumeOffice(int year)
	{

		m_year = year;

	}

	ostream& Minister::write(ostream& os)const
	{

		MemberParliament::write(os);

		os<< "] | [" << m_pmName << "]/[" << m_year << "]" << endl;

		return os;

	}

	istream& Minister::read(istream& in)
	{

		MemberParliament::read(in);

		cout << "Reports TO: ";
		in >> m_pmName;
		cout << "Year Assumed Office: ";
		in >> m_year;

		return in;

	}

	ostream& operator<<(ostream& os, const Minister& min)
	{

		return min.write(os);

	}
	istream& operator>>(istream& in, Minister& min)
	{

		return min.read(in);

	}

}