#include"Basket.h"

namespace sdds
{

	// PRIVATE FUNCTIONS.
	void Basket::setEmpty()
	{

		Fruit* m_fruits = nullptr;
		int m_cnt = 0;
		double m_price = 0.0;

	}

	bool Basket::isvalid(Fruit* fruits, int total, double price)
	{

		return (fruits != nullptr && total > 0 && price > 0);

	}

	Basket::Basket()
	{

		setEmpty();

	}

	Basket::Basket(Fruit* list, int total, double price)
	{

		setEmpty();

		if (isvalid(list, total, price))
		{

			delete[] m_fruits;
			m_fruits = new Fruit[total];
			m_fruits = list;
			m_cnt = total;
			m_price = price;

		}

	}

	Basket::Basket(const Basket& source)
	{

		setEmpty();

		*this = source;

	}

	Basket::~Basket()
	{

		delete[] m_fruits;

	}

	// OPERATORS
	Basket& Basket::operator=(const Basket& source)
	{

		if (*this != source)
		{

			m_cnt = source.m_cnt;
			m_price = source.m_price;
			delete[]m_fruits;
			m_fruits = new Fruit[m_cnt];
			m_fruits = source.m_fruits;

		}

		return *this;

	}

	Basket& Basket::operator+=(Fruit newObject)
	{

		// VARIABLE DECLARATION.
		Fruit* temp = nullptr;

		temp = new Fruit[++m_cnt];
		temp = m_fruits;
		temp[m_cnt] = newObject;
		delete[]m_fruits;
		m_fruits = new Fruit[m_cnt];
		m_fruits = temp;

		return *this;

	}

	Basket::operator bool()const
	{

		return m_cnt > 0;

	}

	// MEMBER FUNCTIONS
	void Basket::setPrice(double price)
	{

		m_price = price;

	}

	void operator<<(ostream& out, Basket RO)
	{

		if (RO.m_cnt > 0)
		{

			for (int i = 0; i < RO.m_cnt; i++)
			{

				out << RO.m_fruits[i].m_name << ": " << RO.m_fruits[i].m_qty << "kg" << endl;

			}

			out << RO.m_price << endl;

		}
		else
		{

			out << "The basket is empty!" << endl;

		}

	}

}