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
#include"ChequingAccount.h"

namespace sdds
{

	// MEMBER FUNCTION.
	void ChequingAccount::setEmpty()
	{

		m_tranFee = 0.0;
		m_monFee = 0.0;

	}

	bool ChequingAccount::debitFees()
	{

		return Account::debit(m_tranFee);

	}

	// CONSTRUCTOR.
	ChequingAccount::ChequingAccount(double initAmt, double tranFee, double monFee):Account(initAmt)
	{
	
		setEmpty();

		if (tranFee>0)
		{

			m_tranFee = tranFee;

		}

		if (monFee>0)
		{

			m_monFee = m_monFee;

		}
	
	}

	// MEMBER FUNCTION.
	bool ChequingAccount::credit(double amtCredit)
	{

		if (Account::credit(amtCredit))
		{

			return debitFees();

		}
		else
		{

			return false;

		}

	}

	bool ChequingAccount::debit(double amtDebit)
	{
	
		if (Account::debit(amtDebit))
		{

			return debitFees();

		}
		else
		{

			return false;

		}
	
	}

	void ChequingAccount::monthEnd()
	{
	
		Account::debit(m_monFee);
	
	}

	void ChequingAccount::display(ostream& out)const
	{
	
		displaytitle("Chequing", Account::balance(), out);
		out << "Per Transaction Fee: " << m_tranFee << endl << "Monthly Fee: " << m_monFee;
	
	}

}