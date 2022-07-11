#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H

#include<iostream>

using namespace std;

namespace sdds
{

	// CLASS.
	class MemberParliament
	{

	protected:

		// DATA MEMBER.
		char m_id[32], m_district[64];
		int m_age;

		void setEmpty();

	public:

		// CONSTRUCTOR.
		MemberParliament();
		MemberParliament(char id[32], int age);

		// MEMBER FUNCTIONS.
		ostream& write(ostream& os)const;
		istream& read(istream& in);

	};

	// HELPER FUNCTION.
	ostream& operator<<(ostream& os, const MemberParliament& m);
	istream& operator>>(istream& in, MemberParliament& m);

}

#endif // !SDDS_MEMBERPARLIAMENT_H
