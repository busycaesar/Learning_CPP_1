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

#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

namespace SDDS {

	const int MAX_NO_OF_RECS = 15;

	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();

}

#endif