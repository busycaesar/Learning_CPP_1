//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 244 NCC                                         //
// SUBMISSION : WORKSHOP 6 PART 2                                   //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I DECLARE THAT THIS SUBMISSION IS THE RESULT OF MY OWN WORK AND  //
// HAS NOT BEEN SHARED WITH ANY OTHR STUDENT OR 3RD PARTY CONTENT   //
// PROVIDER. THIS SUBMITTED PIECE OF WORK IS ENTIRELY OF MY OWN     //
// CREATION.                                                        //
//                                                                  //
//******************************************************************//

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

#include<iostream>

using namespace std;

namespace sdds
{

	struct Fruit
	{

		// VARIABLE DECLARATION.
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms

	};

	class Basket
	{

		// DATA MEMBERS
		Fruit* m_fruits;
		int m_cnt;
		double m_price;

		// PRIVATE FUNCTIONS.
		void setEmpty();
		bool isvalid(Fruit* fruits, int total, double price);

	public:

		// CONSTRUCTORS AND DESTRUCTOR
		Basket();
		Basket(Fruit* list, int total, double price);
		Basket(const Basket& source);
		~Basket();

		// OPERATORS
		Basket& operator=(const Basket& source);
		Basket& operator+=(Fruit newObject);
		operator bool()const;

		// MEMBER FUNCTIONS
		void setPrice(double price);

		// FRIENDS.
		friend void operator<<(ostream& out, Basket& RO);

	};

	// HELPER OPERATOR.
	void operator<<(ostream& out, Basket& RO);

}

#endif // !SDDS_BASKET_H
