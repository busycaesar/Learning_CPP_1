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

// USED HEADER FILE.
#include"SavingsAccount.h"

namespace sdds
{

	// MEMBER FUNCTION.
	void SavingsAccount::setEmpty()
	{

		m_roi = 0.0;

	}

	// CONSTRUCTOR
	SavingsAccount::SavingsAccount(double initAmt, double roi) :Account(initAmt)
	{

		setEmpty();

		if (roi > 0)
		{

			m_roi = roi;

		}

	}

	// MEMBER FUNCTION.
	void SavingsAccount::monthEnd()
	{

		Account::credit(Account::balance() + (Account::balance() * m_roi));

	}

	void SavingsAccount::display(ostream& out)const
	{

		displaytitle("Savings", Account::balance(), out);
		out << "Interest Rate (%): " << m_roi;

	}

}