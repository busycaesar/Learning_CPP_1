#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H

namespace sdds
{

	// CLASS.
	class MemberParliament
	{

		// DATA MEMBER.
		char m_id[32], m_district[64];
		int m_age;

		void setEmpty();

	public:

		// MEMBER FUNCTIONS.
		MemberParliament(char id[32], int age);
		ostream& write(ostream& os);
		istream& read(istream& in);

	};

	// HELPER FUNCTION.
	ostream& operator<<(ostream& os, MemberParliament& m);
	istream& operator>>(istream& in, MemberParliament& m);

}

#endif // !SDDS_MEMBERPARLIAMENT_H
