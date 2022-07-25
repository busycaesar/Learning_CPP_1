#define _CRT_SECURE_NO_WARNINGS

#include"Name.h"

namespace sdds
{
	// MEMBER FUNCTION.
	void Name::setEmpty()
	{

		m_value = nullptr;

	}

	// CONSTRUCTORS.
	Name::Name()
	{

		setEmpty();

	}

	Name::Name(const char* name)
	{

		setEmpty();

		m_value = new char[strlen(name) + 1];
		strcpy(m_value, name);

	}

	Name::Name(const Name& source)
	{

		*this = source;

	}

	// DESTRUCTOR.
	Name::~Name()
	{

		delete[]m_value;
		setEmpty();

	}

	// OPERATORS.
	Name::operator const char* ()const
	{

		return m_value;

	}

	Name& Name::operator=(const Name& source)
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

	Name::operator bool()const
	{

		return (m_value != nullptr);

	}

	// MEMBER FUNCTION.
	std::ostream& Name::display(std::ostream& ostr)const
	{

		if (bool(this))
		{

			ostr << m_value;

		}

		return ostr;

	}

	std::istream& Name::read(std::istream& istr)
	{

		istr >> m_value;

		if (!istr.fail())
		{

			istr.ignore(1);

		}

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