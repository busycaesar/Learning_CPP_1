// USED HEADER FILE.
#include"iAccount.h"
#include"SavingsAccount.h"
#include"ChequingAccount.h"

namespace sdds
{

	iAccount* sdds::CreateAccount(const char* accType, double initBal)
	{

		if (accType[0] == 'S')
		{

			// VARIABLE DECLARATION.
			//SavingsAccount* svngAcc = new SavingsAccount(initBal, );
			// return svngAcc;

		}
		else if (accType[0] == 'C')
		{

			// VARIABLE DECLARATION.
			//ChequingAccount* chqAcc = new ChequingAccount(initBal, 0.0,0.0);
			//return chqAcc;

		}
		else
		{

			return nullptr;
		
		}

	}

}