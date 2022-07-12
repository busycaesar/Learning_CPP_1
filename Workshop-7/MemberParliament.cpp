#define _CRT_SECURE_NO_WARNINGS

#include "MemberParliament.h"
#include"MemberParliament.h"
#include<cstring>
#include<iostream>

using namespace std;

namespace sdds
{

	/*void MemberParliament::setEmpty()
	{

		m_id[0] = '\0';
		strcpy(m_district, "Unassigned");
		m_age = 0;

	}*/

	MemberParliament::MemberParliament()
	{
		strcpy(m_district, "Unassigned");
		//setEmpty();

	}

	MemberParliament::MemberParliament(const char* id, int age)
	{

		//setEmpty();
		strcpy(m_district, "Unassigned");
		strcpy(m_id, id);

		m_age = age;

	}

	void MemberParliament::NewDistrict(const char* district)
	{

		cout << "|[";
		cout.width(8);
		cout << right << m_id;
		cout << "]| |[";
		cout.width(20);
		cout << right << m_district;
		cout << "] ---> [";
		cout.width(23);
		cout << left << district;
		cout << "]|" << endl;

		strcpy(m_district, district);

	}

	ostream& MemberParliament::write(ostream& os)const
	{

		os << "| [" << m_id << "] | [" << m_age << "] | [" << m_district << "]" << end;

		return os;

	}

	istream& MemberParliament::read(istream& in)
	{

		cout << "MP Age: ";
		in >> m_age;
		cout << "MP Id: ";
		in >> m_id;
		cout << "District: ";
		in >> m_district;

		return in;

	}

	ostream& operator<<(ostream& os, const MemberParliament& m)
	{

		return m.write(os);

	}

	istream& operator>>(istream& in, MemberParliament& m)
	{

		return m.read(in);

	}

}