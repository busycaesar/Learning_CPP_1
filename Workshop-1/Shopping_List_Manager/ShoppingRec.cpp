/*********************************************************************************************************/
// Name        : Dev Jigishkumar Shah
// Course      : OOP 244 NCC
// Mail ID     : djshah11@myseneca.ca
// Student ID  : #131623217
// Submission  : Workshop 1 Part 1
// 
// Declaration : 
// All the code was provided to me by the faculty. However, it was in only one module. My work is that 
// I have bifurcated the code in various modules, added namespace, and included other necessary libraries.
/*********************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "ShoppingRec.h"
#include "Utils.h"

using namespace std;

// ----------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------- //
// ------------------------------------------   FUNCTIONS     ------------------------------------ //
// ----------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------- //

namespace SDDS {

	ShoppingRec getShoppingRec() {
		ShoppingRec R = {};
		cout << "Item name: ";
		readCstr(R.m_title, MAX_TITLE_LENGTH);
		cout << "Quantity: ";
		R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
		return R;
	}

	void displayShoppingRec(const ShoppingRec* shp) {
		cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
			" qty:(" << shp->m_quantity << ")" << endl;
	}

	void toggleBoughtFlag(ShoppingRec* rec) {
		rec->m_bought = !rec->m_bought;

	}

	bool isShoppingRecEmpty(const ShoppingRec* shp) {
		return shp->m_title[0] == 0;
	}
}