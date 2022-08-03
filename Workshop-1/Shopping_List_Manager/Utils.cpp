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
#include "Utils.h"

using namespace std;

namespace SDDS {

    void flushkeys() {
        while (cin.get() != '\n');
    }

    bool ValidYesResponse(char ch) {
        return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
    }

    bool yes() {
        char ch = 0;
        do {
            cin >> ch;
            flushkeys();
        } while (!ValidYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");
        return ch == 'y' || ch == 'Y';
    }

    void readCstr(char cstr[], int len) {
        char buf[1024] = {};
        int i;
        cin.getline(buf, 1024);
        for (i = 0; i < len && buf[i]; i++) {
            cstr[i] = buf[i];
        }
        cstr[i] = 0;
    }

    int readInt(int min, int max) {
        int value = 0;
        bool done = false;
        while (!done) {
            cin >> value;
            if (!cin) {
                cin.clear();
                cout << "Bad integer, try agian: ";
            }
            else {
                if (value >= min && value <= max) {
                    done = true;
                }
                else {
                    cout << "Value out of range (" << min << "<=value<=" << max << "): ";
                }
            }
            flushkeys();
        }
        return value;
    }

}