#include"Minister.h"
#include<iostream>

using namespace std;

namespace sdds
{

	void Minister::setEmpty()
	{

		MemberParliament::setEmpty();

		m_pmName[0] = '\0';
		m_year = 0000;

	}

	Minister::Minister(char id[32], int age, int year, char district[64], char pmName[50]) : MemberParliament(id, age)
	{

		setEmpty();

		strcpy(m_district, district);
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

	ostream& Minister::write(ostream& os)
	{

		os << "| [" << m_id << "] | [" << m_age << "] | [" << m_district << "] | [" << m_pmName << "]/[" << m_year << "]" << endl;

	}

	istream& Minister::read(istream& in)
	{

		cout << "Age: ";
		in >> m_age;
		cout << "Id: ";
		in >> m_id;
		cout << "District: ";
		in >> m_district;
		cout << "Reports TO: ";
		in >> m_pmName;
		cout << "Year Assumed Office: ";
		in >> m_year;

	}

	istream& operator>>(istream& in, Minister& minister)
	{}

}