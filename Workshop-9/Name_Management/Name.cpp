#define _CRT_SECURE_NO_WARNINGS

#include<cstring>
#include"Name.h"

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

			*this = source;

		}

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

			if (operator bool())
			{

				delete[] m_fName;
				setEmpty();

			}

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

		if (bool(this))
		{

			ostr << m_fName;

		}

		return ostr;

	}

	std::istream& Name::read(std::istream& istr)
	{

		// VARIABLE DECLARATION.
		char* temp = new char[100];

		istr.get(temp, 99, ' ');


		if (!istr.fail())
		{

			delete[] m_fName;
			setEmpty();
			setFname(temp);
			istr.ignore(1);

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