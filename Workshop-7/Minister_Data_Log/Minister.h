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

#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H

#include"MemberParliament.h"

namespace sdds
{

	// CLASS.
	class Minister : public MemberParliament
	{

		// DATA MEMBER.
		char m_pmName[50];
		int m_year;

		// MEMBER FUNCTION.
		void setEmpty();

	public:

		// CONSTRUCTOR.
		Minister(const char* id, int age, int year, const char* district, const char* pmName);

		// MEMBER FUNCTION.
		void changePM(const char* pm);
		void assumeOffice(int year);
		ostream& write(ostream& os)const;
		istream& read(istream& in);

	};

	// HELPER FUNCTION.
	ostream& operator<<(ostream& os, const Minister& min);
	istream& operator>>(istream& in, Minister& min);

}

#endif // !SDDS_MINISTER_H
