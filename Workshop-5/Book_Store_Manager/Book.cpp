#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Book.h"

using namespace std;

namespace sdds
{

	void Book::init_book()
	{

		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters = 0;
		m_num_pages = 0;

	}

	int Book::add_chapter(const Chapter& chapter)
	{

		(*this)++;
		m_chapters[m_num_chapters] = chapter;
		m_num_pages += (int)m_chapters[m_num_chapters];

		return m_num_chapters;

	}

	Book::Book()
	{

		init_book();

	}

	Book::Book(const char* title_)
	{

		init_book();
		strcpy(m_title, title_);

	}

	Book::Book(const char* title_, const char* author_, double price_)
	{

		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;

	}

	Book Book::operator++(const int i)
	{

		// VARIABLE DECLARATION.
		Book bk = *this;

		++m_num_chapters;

		return bk;

	}

	Book::operator int()
	{

		return m_num_chapters;

	}

	Book::operator bool()
	{

		// VARIABLE DECLARATION.
		bool success = false;

		if (m_title && m_author && m_num_chapters)
		{

			for (int i = 1; i <= m_num_chapters; i++)
			{

				if (m_chapters[i].getNumOfPAges() > 0)
				{

					success = true;
					break;

				}

			}

		}

		return success;

	}

	Book::operator double()
	{

		return m_price;

	}

	Book::operator const char* ()
	{

		return m_title;

	}

	bool Book::operator!=(bool success)
	{

		return !success;

	}

	Book& Book::operator+=(const Chapter& chapter)
	{

		if (MAX_NUM_CHAPTERS > m_num_chapters)
		{

			add_chapter(chapter);

		}

		return *this;

	}

	Book& Book::operator-=(double discount)
	{

		m_price -= discount;

		return *this;

	}

	// Print a book summary
	void Book::summary()
	{

		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;

	}

	ostream& Book::display(ostream& ref)
	{

		ref << "Title:'" << m_title << "'" << endl << "Author: '" << m_author << "'" << endl;

		for (int i = 1; i <= m_num_chapters; i++)
		{

			ref << "| Chapter " << i << "  | ";
			ref.width(20);
			ref << left << (const char*)m_chapters[i] << " |" << endl;

		}

		return ref;

	}

	ostream& operator << (ostream& out, Book& book)
	{

		book.display(out);
		return out;

	}

}