/* ----------------------------------------------------
Workshop 3:
Version: 1.0
Author: Fardad Soleimanloo
Description:
This file tests the BarChart section of your DIY workshop
-----------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

// THIS ARE THE LIBRARY AND HEADER FILES WHICH ARE TO BE INCLUDED.
#include <iostream>
#include "BarChart.h"

// THIS IS TO INFORM THE COMPILER OF THIS LIST OF NAMESPACE USED IN THIS MODULE.
using namespace sdds;
using namespace std;

int main()
{

	// VARIABLE DECLARATION.
	BarChart bc;

	bc.init("How much students like this lab.", 5, '=');

	bc.add("Best Lab Ever", 2);
	bc.add("Good Lab", 10);
	bc.add("Doable Lab", 63);

	cout << "Premature draw call:" << endl;

	bc.draw(); // will not draw; it will print an error instead
	bc.add("Bad Lab", 10);
	bc.add("Worst Lab Ever", 5);

	cout << "Proper draw call after all samples are entered:" << endl;

	bc.draw();
	bc.deallocate();

	// THIS WILL RETURN 0 ON THE SUCCESSFUL EXECUTION OF THIS PROGRAM.
	return 0;

}