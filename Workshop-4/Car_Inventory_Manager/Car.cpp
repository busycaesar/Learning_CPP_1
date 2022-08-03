#define _CRT_SECURE_NO_WARNINGS

#include"Car.h"
#include<cstring>
#include<iostream>

using namespace std;

namespace sdds
{

	void Car::resetInfo()
	{

		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;

		m_year = 0;
		m_code = 0;
		m_price = 0;

	}

	// MEMBER FUNCTION DEFINATION.
	Car::Car()
	{

		resetInfo();

	}

	Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price)
	{

		// THIS WILL CHECK IF THE PROVIDED ARGUMENTS ARE VALID OR NOT.
		if (isValid(type, brand, model, year, code, price))
		{

			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);

			m_year = year;
			m_code = code;
			m_price = price;

		}
		else
		{

			resetInfo();

		}

	}

	Car::~Car()
	{

		m_delete();

	}

	// TO CHECK THE VALIDITY OF THE ARGUMENTS PASSED BY THE CLIENT CODE.
	bool Car::isValid(const char* type, const char* brand, const char* model, int year, int code, double price)
	{

		return (type != nullptr && brand != nullptr && model != nullptr && year >= 1990 && code > 99 && code < 1000 && price>0);

	}

	// TO CHECK THE VALIDITY OF THE MEMBER VARIABLES.
	bool Car::isValid() const
	{

		return (m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code > 99 && m_code < 1000 && m_price>0);

	}

	Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{

		m_delete();

		if (isValid(type, brand, model, year, code, price))
		{

			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);

			m_year = year;
			m_code = code;
			m_price = price;

		}
		else
		{

			resetInfo();

		}

		return *this;

	}

	void Car::printInfo() const
	{

		cout << "| ";

		cout.width(10);
		cout << left << m_type;

		cout << " | ";

		cout.width(16);
		cout << left << m_brand;

		cout << " | ";

		cout.width(16);
		cout << left << m_model;

		cout << " | ";

		cout.width(4);
		cout << m_year;

		cout << " | ";

		cout.width(4);
		cout << right << m_code;

		cout << " | ";

		cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << m_price << " |" << endl;

	}

	bool Car::isSimilarTo(const Car& car) const
	{

		return (car.m_type == m_type && car.m_model == m_model && car.m_brand == m_brand && car.m_year == m_year && car.m_code == m_code && car.m_price == m_price);

	}

	void Car::m_delete()
	{

		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;

		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;

	}

	bool has_similar(const Car car[], const int num_cars)
	{

		// VARIABLE DECLARATION.
		bool success = false;

		for (int i = 0; i < num_cars; i++)
		{

			for (int j = i + 1; j < num_cars; j++)
			{

				// IF THERE IS ANY SIMILAR CAR IN THE WHOLE INVENTORY, IT WLL BE DETECTED. 
				if (car[i].isSimilarTo(car[j]))
				{

					success = true;

				}

			}

		}

		return success;

	}

	bool has_invalid(const Car car[], const int num_cars)
	{

		bool success = false;

		for (int i = 0; i < num_cars; i++)
		{

			// IF THERE IS ANY INVALID CAR IN THE INVENTORY, IT WILL BE DETECTED.
			if (!(car[i].isValid()))
			{

				success = true;

			}

		}

		return success;

	}

	void print(const Car car[], const int num_cars)
	{

		for (int i = 0; i < num_cars; i++)
		{

			// THIS WILL ONLY PRINT THE VALID CARS AND IGNORE THE INVALID CARS.
			if (car[i].isValid())
			{

				car[i].printInfo();

			}

		}

	}

}