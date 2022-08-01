// Workshop 10:
// Write.h
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////

#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_

#include <iostream>

namespace sdds 
{

    // CLASS DECLARATION.
    class ReadWrite 
    {

    public:
        
        // DESTRUCTOR.
        virtual ~ReadWrite() {}
 
        // METHOD.
        virtual std::ostream& display(std::ostream& os)const = 0;
    
    };

    // HELPER FUNCTION.
    std::ostream& operator<<(std::ostream& os, const ReadWrite& c);

}

#endif // !SDDS_READWRITE_H_
