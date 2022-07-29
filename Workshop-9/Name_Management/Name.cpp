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

#include"Name.h"
#include<cstring>

namespace sdds
{
	// MEMBER FUNCTION.
	void Name::setEmpty()
	{

		m_fName = nullptr;

	}

	void Name::setFname(const char* fName)
	{

		m_fName = new char[strlen(fName) + 1];
		strcpy(m_fName, fName);

	}

	// CONSTRUCTORS.
	Name::Name()
	{

		setEmpty();

	}

	Name::Name(const char* name)
	{

		setEmpty();

		if (name != nullptr)
		{

			setFname(name);

		}

	}

	// RULE 1. COPY CONSTRUCTOR.
	Name::Name(const Name& source)
	{

		setEmpty();

		if (bool(source))
		{

			setFname(source.m_fName);

		}

	}

	// DESTRUCTOR.
	// RULE 3. DESTRUCTOR.
	Name::~Name()
	{

		delete[] m_fName;

	}

	// OPERATORS.
	Name::operator const char* ()const
	{

		return m_fName;

	}

	// RULE 2. COPY ASSIGNMENT OPERATOR.
	Name& Name::operator=(const Name& source)
	{

		if (this != &source)
		{

			delete[] m_fName;
			setEmpty();

			if (bool(source))
			{

				setFname(source.m_fName);

			}

		}

		return *this;

	}

	Name::operator bool()const
	{

		return (m_fName != nullptr);

	}

	// MEMBER FUNCTION.
	std::ostream& Name::display(std::ostream& ostr)const
	{

		if (operator bool())
		{

			ostr << m_fName;

		}

		return ostr;

	}

	std::istream& Name::read(std::istream& istr)
	{

		// VARIABLE DECLARATION.
		char* temp = new char[200];

		istr.getline(temp, 199, ' ');

		delete[] m_fName;
		setEmpty();

		if (istr)
		{

			setFname(temp);

		}

		delete[] temp;

		return istr;

	}

	std::ostream& operator<<(std::ostream& os, Name& source)
	{

		source.display(os);
		return os;

	}

	std::istream& operator>>(std::istream& in, Name& source)
	{

		source.read(in);
		return in;

	}

}