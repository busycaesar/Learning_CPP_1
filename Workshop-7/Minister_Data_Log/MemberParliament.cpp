//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 244 NCC                                         //
// SUBMISSION : WORKSHOP 7 (LAB)                                    //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I DECLARE THAT THIS SUBMISSION IS THE RESULT OF MY OWN WORK AND  //
// HAS NOT BEEN SHARED WITH ANY OTHR STUDENT OR 3RD PARTY CONTENT   //
// PROVIDER. THIS SUBMITTED PIECE OF WORK IS ENTIRELY OF MY OWN     //
// CREATION.                                                        //
//                                                                  //
//******************************************************************//

#define _CRT_SECURE_NO_WARNINGS

#include "MemberParliament.h"
#include"MemberParliament.h"
#include<cstring>
#include<iostream>

using namespace std;

namespace sdds
{

	void MemberParliament::setEmpty()
	{

		m_id[0] = '\0';
		strcpy(m_district, "Unassigned");
		m_age = 0;

	}

	MemberParliament::MemberParliament()
	{
		
		setEmpty();

	}

	MemberParliament::MemberParliament(const char* id, int age)
	{

		setEmpty();
		strcpy(m_id, id);
		m_age = age;

	}

	void MemberParliament::NewDistrict(const char* district)
	{

		cout << "|";
		cout.width(8);
		cout << right << m_id;
		cout << "| |";
		cout.width(20);
		cout << right << m_district;
		cout << " ---> ";
		cout.width(23);
		cout << left << district;
		cout << "|" << endl;

		strcpy(m_district, district);

	}

	ostream& MemberParliament::write(ostream& os)const
	{

		os << "| " << m_id << " | " << m_age << " | " << m_district;

		return os;

	}

	istream& MemberParliament::read(istream& in)
	{

		cout << "Age: ";
		in >> m_age;
		cout << "Id: ";
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