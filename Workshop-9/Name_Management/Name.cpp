#define _CRT_SECURE_NO_WARNINGS

#include"Name.h"
#include <string>
namespace sdds
{
	// MEMBER FUNCTION.
	void Name::setEmpty()
	{

		m_fName = nullptr;

	}

	// CONSTRUCTORS.
	Name::Name()
	{

		setEmpty();

	}

	Name::Name(const char* name)
	{

		setEmpty();

	}

	// RULE 1. COPY CONSTRUCTOR.
	Name::Name(const Name& source)
	{

		setEmpty();
		*this = source;

	}

	// DESTRUCTOR.
	// RULE 3. DESTRUCTOR.
	Name::~Name()
	{

		delete[] m_fName;
		setEmpty();

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

			delete[]m_fName;
			setEmpty();

			m_fName = new char[strlen(source.m_fName) + 1];
			strcpy(m_fName, source.m_fName);

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

		if (bool(this))
		{

			ostr << m_fName;

		}

		return ostr;

	}

	std::istream& Name::read(std::istream& istr)
	{

		// VARIABLE DECLARATION.
		char temp[100];

		istr.get(temp, 100, ' ');
		istr.ignore(1);
		
		delete[] m_fName;
		m_fName = nullptr;

		m_fName = new char[strlen(temp) + 1];
		strcpy(m_fName, temp);

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