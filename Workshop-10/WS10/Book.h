// Workshop 10:
// Collection template
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////

#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_

#include <iostream>
#include "Write.h"

namespace sdds
{

	// CLASS DECLARATION.
	class Book : public ReadWrite
	{

		// DATA MEMBER.
		int m_upc;
		char m_title[41], m_author[41];
		double m_price;

	public:

		// CONSTRUCTOR.
		Book();
		Book(int upc, const char* title, const char* author, double price);
		
		// OPERATOR.
		bool operator==(int upc)const;
		bool operator==(const char* title)const;

		// METHOD.
		void set(int upc, const char* title, const char* author, double price);
		std::ostream& display(std::ostream& os)const;

	};

	// HELPER FUNCTION.
	std::ostream& operator<<(std::ostream& os, const Book& book);

}

#endif // !SDDS_BOOK_H_