//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 244 NCC                                         //
// SUBMISSION : WORKSHOP - 10 (PART 1)                              //
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

#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_

#include <iostream>
#include "Collection.h"

using namespace std;

namespace sdds
{

	//Find with 3 parameters
	template<typename type0, typename type1>
	bool find(type0 f_array, int f_index, type1 f_value)
	{

		return (f_array[f_index] == f_value);

	}
	// THE ABOVE FUNCTION REQUIRES A FUNCTION CALL WITH THE ARGUMENTS IN THE FOLLOWING SEQUENCE: AN OBJECT OF COLLECTION TYPE, THE INDEX OF THE ARRAY, AND A VALUE TO LOOK FOR WITHIN THE ARRAY.  

	//Find with 4 parameters
	template<typename type0, typename type1, typename type2>
	int find(type0 f_array, int f_arrsize, type1 f_value0, type2 f_value1)
	{

		// VARIABLE DECLARATION.
		int t_index = -1, t_i = 0;

		while (t_i < f_arrsize)
		{

			if (find(f_array, t_i, f_value0) && find(f_array, t_i, f_value1)) t_index = t_i;
			t_i++;

		}

		return t_index;

	}
	// THE ABOVE FUNCTION REQUIRES A FUNCTION CALL WITH THE ARGUMENTS IN THE FOLLOWING SEQUENCE: AN OBJECT OF COLLECTION TYPE, THE SIZE OF THE ARRAY, AND TWO VALUES TO LOOK FOR WITHIN THE ARRAY.

		//Insertion operator
	template<typename type0>
	ostream& operator<<(ostream& f_out, Collection<type0>& f_object)
	{

		for (int i = 0; i < f_object.size(); i++)
		{

			f_out << f_object[i] << endl;

		}

		return f_out;

	}
	// THE ABOVE FUNCTION REQUIRES A FUNCTION CALL WHERE AN OBJECT OF COLLECTION TYPE IS INSERTED INTO THE OSTREAM OBJECT.

	//Load Collection
	template<typename type0>
	const Collection<type0>& loadCollection(Collection<type0>& f_main, type0 f_newItem)
	{

		f_main += f_newItem;

		return f_main;

	}
	// THE ABOVE FUNCTION REQUIRES A FUNCTION CALL WITH THE ARGUMENTS IN THE FOLLOWING SEQUENCE: AN OBJECT OF COLLECTION TYPE, AND A NEW ITEM TO BE ADDED OF THE SAME TYPE AS OF THE OBJECT OF THE COLLECTION.

}

#endif // !SDDS_SEARCH_H_
