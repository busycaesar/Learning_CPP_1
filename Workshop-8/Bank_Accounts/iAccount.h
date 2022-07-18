//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 244 NCC                                         //
// SUBMISSION : WORKSHOP - 8 (PART 1)                               //
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

#ifndef SDDS_IACCOUNT_H
#define SDDS_IACCOUNT_H

// USED HEADER FILES.
#include<iostream>

// USED NAME SPACES.
using namespace std;

namespace sdds
{

	// CLASS.
	class iAccount
	{

	public:

		// DESTRUCTOR.
		virtual ~iAccount() = 0;

		// MEMBER FUNCTION.
		virtual bool credit(double amoCredit) = 0;
		virtual bool debit(double amoDebit) = 0;
		virtual void monthEnd() = 0;
		virtual void display(ostream& out)const = 0;

	};

	// HELPER FUNCTION.
	iAccount* CreateAccount(const char* accType, double initBal);

}

#endif // !SDDS_IACCOUNT_H
