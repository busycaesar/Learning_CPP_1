#define _CRT_SECURE_NO_WARNINGS

#include"FullName.h"

namespace sdds
{

	// MEMBER FUNCTIONS.
	void FullName::setEmpty()
	{

		m_value = nullptr;

	}

	// CONSTRUCTOR.
	FullName::FullName()
	{

		setEmpty();

	}
	FullName::FullName(const char* name, const char* lastName) :Name(name)
	{

		setEmpty();

		m_value = new char[strlen(lastName) + 1];
		strcpy(m_value, lastName);

	}

	FullName::FullName(const FullName& source)
	{

		*this = source;

	}

	// DESTRUCTOR.
	FullName::~FullName()
	{

		delete[] m_value;

		setEmpty();

	}

	// TYPE CASTERS.
	FullName::operator const char* ()const
	{

		return m_value;

	}
	FullName::operator bool()const
	{

		return (Name::operator bool() && m_value != nullptr);

	}

	// OPERATORS.
	FullName& FullName::operator=(const FullName& source)
	{

		if (this != &source)
		{

			delete[]m_value;
			setEmpty();

			m_value = new char[strlen(source.m_value) + 1];
			strcpy(m_value, source.m_value);

		}

		return *this;

	}

	// MEMBER FUNCTIONS.
	std::ostream& FullName::display(std::ostream& ostr)const
	{

		if (bool(this))
		{

			Name::display(ostr);
			ostr << " " << m_value;

		}

		return ostr;

	}

	std::istream& FullName::read(std::istream& istr)
	{
	
		Name::read(istr);

		istr.get(m_value, '\n');
		istr.ignore('\n');

		return istr;

	}

}