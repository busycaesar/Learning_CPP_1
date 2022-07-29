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

#define _CRT_SECURE_NO_WARNINGS

#include<cstring>
#include"FullName.h"

namespace sdds
{

	// MEMBER FUNCTIONS.
	void FullName::setEmpty()
	{

		m_lName = nullptr;

	}

	void FullName::setlName(const char* lName)
	{

		m_lName = new char[strlen(lName) + 1];
		strcpy(m_lName, lName);

	}

	// CONSTRUCTOR.
	FullName::FullName() :Name()
	{

		setEmpty();

	}
	FullName::FullName(const char* fName, const char* lName) :Name(fName)
	{

		setEmpty();

		if (lName != nullptr)
		{

			setlName(lName);

		}

	}

	// RULE 1. COPY CONSTRUCTOR.
	FullName::FullName(const FullName& source) : Name(source)
	{

		setEmpty();

		if (bool(source))
		{

			setlName(source.m_lName);

		}

	}

	// DESTRUCTOR.
	// RULE 3. DESTRUCTOR.
	FullName::~FullName()
	{

		delete[] m_lName;

	}

	// TYPE CASTERS.
	FullName::operator const char* ()const
	{

		return m_lName;

	}
	FullName::operator bool()const
	{

		return (Name::operator bool() && m_lName != nullptr);

	}

	// OPERATORS.
	// RULE 2. COPY ASSIGNMENT OPERATOR.
	FullName& FullName::operator=(const FullName& source)
	{

		if (this != &source)
		{

			Name::operator=(source);

			delete[] m_lName;
			setEmpty();

			if (bool(source))
			{

				setlName(source.m_lName);

			}

		}

		return *this;

	}

	// MEMBER FUNCTIONS.
	std::ostream& FullName::display(std::ostream& ostr)const
	{

		if (bool(this))
		{

			Name::display(ostr);
			ostr << " " << m_lName;

		}

		return ostr;

	}

	std::istream& FullName::read(std::istream& istr)
	{

		Name::read(istr);

		// VARIABLE DECLARATION.
		char* temp = new char[200];

		istr.getline(temp, 199, '\n');

		delete[] m_lName;
		setEmpty();

		if (istr)
		{

			setlName(temp);

		}

		delete[] temp;

		return istr;

	}

}