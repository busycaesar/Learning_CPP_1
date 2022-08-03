#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_

#include <iostream>
#include "Chapter.h"

using namespace std;

namespace sdds
{

	// VARIABLE DECLARATION.
	const int MAX_NUM_CHAPTERS = 10;
	const int MAX_BOOK_TITEL = 40;
	const int MAX_AUTHOR_NAME = 20;

	// CLASS DECLARATION.
	class Book
	{

		// MEMBER VARIABLES.
		char m_title[MAX_BOOK_TITEL + 1];
		char m_author[MAX_AUTHOR_NAME + 1];
		int m_num_chapters;
		int m_num_pages;
		double m_price;
		Chapter m_chapters[MAX_NUM_CHAPTERS];

		// MEMBER FUNCTIONS.
		void init_book();
		int add_chapter(const Chapter& chapter);

	public:

		// CONSTRUCTORS.
		Book();
		Book(const char* title_);
		Book(const char* title_, const char* author_, double price_);

		// MEMBER FUNCTIONS.OPERATORS.
		Book operator++(const int i);
		operator int();
		operator bool();
		operator double();
		operator const char* ();
		bool operator!=(bool success);
		Book& operator+=(const Chapter& chapter);
		Book& operator-=(double discount);

		void summary(); // Print a book summary
		ostream& display(ostream& ref);

		// FRIEND.
		friend ostream& operator << (ostream& out, Book& book);

	};

}
#endif