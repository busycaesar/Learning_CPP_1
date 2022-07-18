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

#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H

// USED HEADER FILE.
#include"iAccount.h"

namespace sdds
{

	// CLASS.
	class Account : public iAccount
	{

		// MEMBER VARIABLE.
		double m_currBal;
		
		// MEMBER FUNCTION.
		void setEmpty();

	public:

		// CONSTRUCTOR.
		Account(double initBal = 0);

		// MEMBER FUNCTION.
		bool credit(double amtCredit);
		bool debit(double amtDebit);
		double balance()const;

	};

	ostream& displaytitle(const char* accType, double currBal, ostream& out);

}

#endif // !SDDS_ACCOUNT_H
