#ifndef SDDS_NAME_H
#define SDDS_NAME_H

#include<iostream>

namespace sdds
{

	// CLASS
	class Name // BASE CLASS.
	{

		// VARIABLE DECLARATION.
		char* m_fName;

		// MEMBER FUNCTION.
		void setEmpty(); // SETS THE DATA MEMBER TO NULL.
		void setFname(const char* fName); // ALLOCATES THE DYNAMIC MEMORY TO THE VARIABLE AND COPIES THE CHARACTER INTO IT.

	public:

		// CONSTRUCTOR.
		Name();
		Name(const char* name);

		// RULE 1. COPY CONSTRUCTOR.
		Name(const Name& source);

		// DESTRUCTOR.
		// RULE 3. DESTRUCTOR.
		~Name();

		// TYPE CASTING.
		operator const char* ()const;
		virtual operator bool()const;
		
		// OPERATOR.
		// RULE 2. COPY ASSIGNMENT OPERATOR.
		Name& operator=(const Name& source);

		// MEMBER FUNCTION.
		virtual std::ostream& display(std::ostream& ostr = std::cout)const;
		virtual std::istream& read(std::istream& istr = std::cin);

	};

	std::ostream& operator<<(std::ostream& os, Name& source);
	std::istream& operator>>(std::istream& in, Name& source);
	
}

#endif // !SDDS_NAME_H