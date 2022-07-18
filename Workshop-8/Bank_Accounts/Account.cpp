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
#include"Account.h"

namespace sdds
{

	// MEMBER FUNCTION.
	void Account::setEmpty()
	{

		m_currBal = 0.0;

	}

	// CONSTRUCTOR.
	Account::Account(double initBal)
	{

		setEmpty();

		if (initBal > 0)
		{

			m_currBal = initBal;

		}

	}

	// MEMBER FUNCTION.
	bool Account::credit(double amtCredit)
	{

		if (amtCredit > 0)
		{

			m_currBal += amtCredit;
			return true;

		}
		else
		{

			return false;

		}

	}

	bool Account::debit(double amtDebit)
	{

		if (amtDebit > 0)
		{

			m_currBal -= amtDebit;
			return true;

		}
		else
		{

			return false;

		}

	}

	double Account::balance()const
	{
	
		return m_currBal;
	
	}

	ostream& sdds::displaytitle(const char* accType, double currBal, ostream& out)
	{

		out << "Account type: " << accType << endl << "Balance: " << currBal << endl;

		return out;

	}

}