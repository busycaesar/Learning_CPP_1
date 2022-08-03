#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include "Chapter.h"

using namespace std;

namespace sdds
{

	void Chapter::init_chapter()
	{

		m_title[0] = '\0';
		m_num_pages = 0;
		m_num_words = 0;
		m_chapter_number = 0;

	}

	Chapter::Chapter()
	{

		init_chapter();

	}

	Chapter::Chapter(const char* title_)
	{

		init_chapter();
		strcpy(m_title, title_);

	}

	Chapter::Chapter(const char* title_, int chapter_num, int n_pages, int n_words)
	{

		strcpy(m_title, title_);
		m_chapter_number = chapter_num;
		m_num_pages = n_pages;
		m_num_words = n_words;

	}

	Chapter::operator int()
	{

		return m_num_pages;

	}

	Chapter::operator double()
	{

		return ((double)m_num_words / m_num_pages);

	}

	Chapter::operator const char* ()
	{

		return m_title;

	}

	Chapter& Chapter::operator = (const Chapter& assignThis)
	{

		strcpy(m_title, assignThis.m_title);
		m_chapter_number = assignThis.m_chapter_number;
		m_num_pages = assignThis.m_num_pages;
		m_num_words = assignThis.m_num_words;

		return *this;

	}

	Chapter& Chapter::operator ++ ()
	{

		++m_num_pages;

		return *this;

	}

	Chapter& Chapter::operator -- ()
	{

		--m_num_pages;

		return *this;

	}

	ostream& Chapter::display(ostream& os)const
	{

		os.setf(std::ios::left);
		os << "| Chapter ";
		os.width(2);
		os << m_chapter_number << " | ";
		os.width(MAX_CHAPTER_TITLE);
		os << m_title << " |" << endl;

		return os;

	}

	int Chapter::getNumOfPAges()
	{

		return m_num_pages;

	}

	ostream& operator << (ostream& out, Chapter& chapter)
	{

		chapter.display(out);
		return out;

	}

}
