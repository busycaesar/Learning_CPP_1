#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds
{

	// DECLARING CLASSES.
	class Car
	{
		// DECLARING VARIABLES.
		char* m_type, * m_brand, * m_model;
		int m_year, m_code;
		double m_price;

		// MEMBER FUNCTION.
		void resetInfo();

	public:

		Car();
		Car(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
		~Car();
		bool isValid(const char* type, const char* brand, const char* model, int year, int code, double price);
		bool isValid()const;
		Car& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isSimilarTo(const Car& car) const;
		void m_delete();

	};

	// FUNCTION SIGNATURES.
	bool has_similar(const Car car[], const int num_cars);
	bool has_invalid(const Car car[], const int num_cars);
	void print(const Car car[], const int num_cars);

}

#endif // !SDDS_CAR_H
