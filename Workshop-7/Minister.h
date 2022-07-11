#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H

#include"MemberParliament.h"

namespace sdds
{

	// CLASS.
	class Minister : public MemberParliament
	{

		// DATA MEMBER.
		char m_pmName[50];
		int m_year;

		// MEMBER FUNCTION.
		void setEmpty();

	public:

		// CONSTRUCTOR.
		Minister(char id[32], int age, int year, char district[64], char pmName[50]);

		// MEMBER FUNCTION.
		void changePM(const char* pm);
		void assumeOffice(int year);
		ostream& write(ostream& os)const;
		istream& read(istream& in);

	};

	// HELPER FUNCTION.
	ostream& operator<<(ostream& os,const Minister& min);
	istream& operator>>(istream& in, Minister& min);

}

#endif // !SDDS_MINISTER_H