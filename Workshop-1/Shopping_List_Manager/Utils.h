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

#ifndef SDDS_UTUILS_H
#define SDDS_UTUILS_H

namespace SDDS {

    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);

}

#endif