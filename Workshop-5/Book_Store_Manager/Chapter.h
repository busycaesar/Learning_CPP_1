#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_

#include <iostream>

using namespace std;

namespace sdds {

	// VARIABLE DECLARATION.
	const int MAX_CHAPTER_TITLE = 20;

	// CLASS DECLARATION.
	class Chapter
	{

		// VARIABLE DECLARATION.
		char m_title[MAX_CHAPTER_TITLE + 1];
		int m_num_pages;
		int m_num_words;
		unsigned int m_chapter_number;

		// MEMBER FUNCTIONS.
		void init_chapter();

	public:

		// CONSTRUCTORS.
		Chapter();
		Chapter(const char* title_);
		Chapter(const char* title_, int chapter_num, int n_pages, int n_words);

		// OPERATORS.
		operator int();
		operator double();
		operator const char* ();
		Chapter& operator = (const Chapter& assignThis);
		Chapter& operator ++ ();
		Chapter& operator -- ();

		std::ostream& display(std::ostream&)const;
		int getNumOfPAges();

	};

	// HELPER OPERATORS.
	ostream& operator << (ostream& out, Chapter& chapter);

}
#endif

