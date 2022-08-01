// Workshop 10:
// Pet.h
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////

#ifndef SDDS_PET_H_
#define SDDS_PET_H_

#include <iostream>
#include "Write.h"

namespace sdds
{

	// CLASS DECLARATION.
	class Pet : public ReadWrite
	{

		// DATA MEMBER.
		char m_name[41], m_type[41];
		int m_age;

	public:

		// CONSTRUCTOR.
		Pet();
		Pet(const char* name, const char* type, int age);
	
		// OPERATOR.
		bool operator==(const char* type)const;
		bool operator==(const int age)const;
	
		// METHOD.
		void set(const char* name, const char* type, int age);
		std::ostream& display(std::ostream& os)const;
		
	};

	// HELPER FUNCTION.
	std::ostream& operator<<(std::ostream& os, const Pet& Pet);

}

#endif // !SDDS_PET_H_
