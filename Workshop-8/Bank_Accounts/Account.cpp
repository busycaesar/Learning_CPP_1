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

#define _CRT_SECURE_NO_WARNINGS

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

		// VARIABLE DECLARATION.
		bool success = false;

		if (amtCredit > 0)
		{

			m_currBal += amtCredit;
			success = true;

		}

		return success;

	}

	bool Account::debit(double amtDebit)
	{

		// VARIABLE DECLARATION.
		bool success = false;

		if (amtDebit > 0)
		{

			m_currBal -= amtDebit;
			success = true;

		}

		return success;

	}

	double Account::balance()const
	{

		return m_currBal;

	}

	ostream& sdds::displaytitle(const char* accType, double currBal, ostream& out)
	{

		out.setf(ios::fixed);
		out.precision(2);
		out << "Account type: " << accType << endl << "Balance: $"<< currBal << endl;

		return out;

	}

}