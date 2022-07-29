//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 244 NCC                                         //
// SUBMISSION : WORKSHOP PART - 1                                   //
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

#ifndef SDDS_FULLNAME_H
#define SDDS_FULLNAME_H

#include"Name.h"

namespace sdds
{

	// CLASS
	class FullName : public Name
	{

		// DATA MEMBER.
		char* m_lName;

		// MEMBER FUNCTIONS.
		void setEmpty();
		void setlName(const char* lName);

	public:

		// CONSTRUCTOR.
		FullName();
		FullName(const char* fName, const char* lName);

		// RULE 1. COPY CONSTRUCTOR.
		FullName(const FullName& source);

		// DESTRUCTOR.
		// RULE 3. DESTRUCTOR.
		~FullName();

		// TYPE CASTING.
		operator const char* ()const;
		virtual operator bool()const;

		// OPERATORS.
		// RULE 2. COPY ASSIGNMENT OPERATOR.
		FullName& operator=(const FullName& source);

		// MEMBER FUNCTIONS.
		virtual std::ostream& display(std::ostream& ostr = std::cout)const;
		virtual std::istream& read(std::istream& istr = std::cin);

	};

}

#endif // !SDDS_FULLNAME_H
