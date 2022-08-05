// Workshop 10:
// Card.h
// 2022-02-19
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////

#ifndef SDDS_CARD_H_
#define SDDS_CARD_H_

#include <iostream>
#include "Write.h"

namespace sdds
{

    // CLASS DECLARATION,
    class Card : public ReadWrite
    {

        // DATA MEMBER.
        char m_suit[10];
        int m_value;

    public:

        // CONSTRUCTOR.
        Card(const char* suit = "", const int value = 0);

        // OPERATOR.
        bool operator==(const char* mmSubstr)const;
        bool operator==(const int mmVal)const;

        // METHOD.
        void set(const char* suit, const int value);
        std::ostream& display(std::ostream& os)const;

    };

    // HELPER FUNCTION.

    std::ostream& operator<<(std::ostream& os, const Card& card);

}

#endif // !SDDS_CARD_H_