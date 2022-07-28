#define _CRT_SECURE_NO_WARNINGS

#include"FullName.h"

namespace sdds
{

	// MEMBER FUNCTIONS.
	void FullName::setEmpty()
	{

		m_lName = nullptr;

	}

	// CONSTRUCTOR.
	FullName::FullName()
	{

		setEmpty();

	}
	FullName::FullName(const char* name, const char* lastName) :Name(name)
	{

		setEmpty();

		m_lName = new char[strlen(lastName) + 1];
		strcpy(m_lName, lastName);

	}

	FullName::FullName(const FullName& source)
	{

		setEmpty();
		*this = source;

	}

	// DESTRUCTOR.
	FullName::~FullName()
	{

		delete[] m_lName;
		setEmpty();

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
	FullName& FullName::operator=(const FullName& source)
	{

		if (this != &source)
		{

			delete[] m_lName;
			setEmpty();

			m_lName = new char[strlen(source.m_lName) + 1];
			strcpy(m_lName, source.m_lName);

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
		char temp[100];

		istr.get(temp, 100, '\n');
		istr.ignore(1);

		delete[] m_lName;
		m_lName = nullptr;

		m_lName = new char[strlen(temp) + 1];
		strcpy(m_lName, temp);

		return istr;

	}

}