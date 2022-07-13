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

#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H

#include<iostream>

using namespace std;

namespace sdds
{

	// CLASS.
	class MemberParliament
	{

		// DATA MEMBER.
		char m_id[32], m_district[64];
		int m_age;

		void setEmpty();

	public:

		// CONSTRUCTOR.
		MemberParliament();
		MemberParliament(const char* id, int age);

		void NewDistrict(const char* district);

		// MEMBER FUNCTIONS.
		ostream& write(ostream& os)const;
		istream& read(istream& in);

	};

	// HELPER FUNCTION.
	ostream& operator<<(ostream& os, const MemberParliament& m);
	istream& operator>>(istream& in, MemberParliament& m);

}

#endif // !SDDS_MEMBERPARLIAMENT_H
