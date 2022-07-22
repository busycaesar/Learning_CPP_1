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

#ifndef SDDS_SAVINGSACCOUNT_H
#define SDDS_SAVINGSACCOUNT_H

#include"Account.h"

// USED NAMESPACE.
using namespace std;

namespace sdds
{


	// CLASS.
	class SavingsAccount :public Account
	{

		// DATA MEMBER.
		double m_roi;

		// MEMBER FUNCTION.
		void setEmpty();

	public:

		// CONSTRUCTOR
		SavingsAccount(double initAmt, double roi);

		// MEMBER FUNCTION.
		void monthEnd();
		void display(ostream& out)const;

	};

}

#endif // !SDDS_SAVINGSACCOUNT_H
