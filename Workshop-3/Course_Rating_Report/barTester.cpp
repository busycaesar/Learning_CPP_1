/*----------------------------------------------------
Workshop 3:
Version: 1.0
Author: Fardad Soleimanloo
Description:
This file tests the Bar class of your DIY workshop
----------------------------------------------------*/

// THIS ARE THE LIBRARY AND HEADER FILES WHICH ARE TO BE INCLUDED.
#include "Bar.h"

// THIS IS TO INFORM THE COMPILER OF THIS LIST OF NAMESPACE USED IN THIS MODULE.
using namespace sdds;

int main() 
{

    // VARIABLE DECLARATION.
    Bar b;

    for (int i = 1; i <= 5; i++) 
    {
    
        b.set("the bar", '=', i * 20);
        b.draw();
    
    }

    b.set("Bad Bar", '=', -200);
    b.draw();
    b.set("Bad Bar", '=', 200);
    b.draw();

    // THIS WILL RETURN 0 ON SUCCESSFULL EXECUTION OF THIS PROGRAM.
    return 0;

}