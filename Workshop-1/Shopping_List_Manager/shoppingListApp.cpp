/*********************************************************************************************************/
// Name        : Dev Jigishkumar Shah
// Course      : OOP 244 NCC
// Mail ID     : djshah11@myseneca.ca
// Student ID  : #131623217
// Submission  : Workshop 1 Part 1
// Date        : 2022 / 05 / 20
// 
// Declaration : 
// All the code was provided to me by the faculty. However, it was in only one module. My work is that 
// I have bifurcated the code in various modules, added namespace, and included other necessary libraries.
/*********************************************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstdlib>

#include "ShoppingRec.h"
#include "File.h"
#include "ShoppingList.h"
#include "Utils.h"

using namespace std;
using namespace SDDS;

// set to false when compling on Linux
const bool APP_OS_WINDOWS = false;

int listMenu();

int main() {
	bool done = false;
	loadList();
	while (!done) {
		system(APP_OS_WINDOWS ? "cls" : "clear");
		switch (listMenu()) {
		case 1:
			toggleBought();
			break;
		case 2:
			addItemToList();
			break;
		case 3:
			removeItemfromList();
			break;
		case 4:
			removeBoughtItems();
			break;
		case 5:
			clearList();
			break;
		default:
			done = true;
		}
	}
	saveList();
	return 0;
}

int listMenu() {
	cout << "-->>> My Shopping List <<<--" << endl;
	displayList();
	cout << "----------------------------" << endl
		<< "1- Toggle bought Item" << endl
		<< "2- Add Shopping Item" << endl
		<< "3- Remove Shopping Item" << endl
		<< "4- Remove bought Items" << endl
		<< "5- Clear List" << endl
		<< "0- Exit" << endl << "> ";
	return readInt(0, 5);
}