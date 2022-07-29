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

			*this = source;

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

			// THIS WILL TAKE CARE OF THE NAME PART OF THE OBJECT.
			if (Name::operator bool())
			{

				Name::operator=(source);

			}

			if (operator bool())
			{

				delete[] m_lName;
				setEmpty();

			}

			setlName(source.m_lName);

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
		char* temp = new char[100];

		istr.get(temp, 99, '\n');

		if (!istr.fail())
		{

			delete[] m_lName;
			setEmpty();
			setlName(temp);
			istr.ignore(1);

		}

		delete[] temp;

		return istr;

	}

}