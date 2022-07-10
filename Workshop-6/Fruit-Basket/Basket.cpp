#include<iostream>
#include"Basket.h"

using namespace std;

namespace sdds
{

	// PRIVATE FUNCTIONS.
	void Basket::setEmpty()
	{

		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0.0;

	}

	bool Basket::isvalid(Fruit* fruits, int total, double price)
	{

		return (fruits != nullptr && total > 0 && price > 0.0);

	}

	// CONSTRUCTORS AND DESTRUCTOR.
	Basket::Basket()
	{

		setEmpty();

	}

	Basket::Basket(Fruit* list, int total, double price)
	{

		setEmpty();

		if (isvalid(list, total, price))
		{

			m_fruits = new Fruit[total];

			for (int i = 0; i < total; i++)
			{

				m_fruits[i] = list[i];

			}

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
		m_fruits = nullptr;

	}

	// OPERATORS
	Basket& Basket::operator=(const Basket& source)
	{

		if (this != &source)
		{

			m_cnt = source.m_cnt;
			m_price = source.m_price;

			delete[] m_fruits;
			m_fruits = nullptr;

			m_fruits = new Fruit[m_cnt];

			for (int i = 0; i < m_cnt; i++)
			{

				m_fruits[i] = source.m_fruits[i];

			}

		}

		return *this;

	}

	Basket& Basket::operator+=(Fruit newObject)
	{

		// VARIABLE DECLARATION.
		Fruit* temp = new Fruit[m_cnt + 1];

		for (int i = 0; i < m_cnt; i++)
		{

			temp[i] = m_fruits[i];

		}

		temp[m_cnt] = newObject;
		m_cnt++;

		delete[] m_fruits;

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

	void operator<<(ostream& out, Basket& RO)
	{

		if (RO.m_cnt > 0)
		{

			out << "Basket Content:" << endl;

			for (int i = 0; i < RO.m_cnt; i++)
			{

				out.width(11);
				out << right << RO.m_fruits[i].m_name<<": ";
				out.fixed;
				out.precision(2);
				out << RO.m_fruits[i].m_qty << "Kg"<<endl;

			}

			out.precision(2);
			out << "Price:" << RO.m_price << endl;

		}
		else
		{

			out << "The basket is empty!" << endl;

		}

	}

}