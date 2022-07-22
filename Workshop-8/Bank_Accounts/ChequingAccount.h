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

#ifndef SDDS_CHEQUINGACCOUNT_H
#define SDDS_CHEQUINGACCOUNT_H

// USED HEADER FILE.
#include"Account.h"

// USED NAMESPACE.
using namespace std;

namespace sdds
{

	// CLASS.
	class ChequingAccount :public Account
	{

		// DATA MEMBER.	
		double m_tranFee, m_monFee;

		// MEMBER FUNCTION.
		void setEmpty();
		bool debitFees();

	public:

		// CONSTRUCTOR.
		ChequingAccount(double initAmt, double tranFee, double monFee);

		// MEMBER FUNCTION.
		bool credit(double amtCredit);
		bool debit(double amtDebit);
		void monthEnd();
		void display(ostream& out)const;

	};

}

#endif // !SDDS_CHEQUINGACCOUNT_H