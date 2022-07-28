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

	public:

		// CONSTRUCTOR.
		FullName();
		FullName(const char* name, const char* lastName);
		
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
