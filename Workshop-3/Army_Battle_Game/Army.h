#ifndef SDDS_ARMY_H
#define SDDS_ARMY_H

namespace sdds
{

	// CONSTANT DECLARATION.
	const int MAX_NAME_LEN = 50;

	// CREATING CLASSES.
	class Army
	{

		// VARIABLE DECLARATION.
		char m_armNationality[MAX_NAME_LEN];
		int m_armUnits;
		double m_armPower;

		// ALL OF THE FOLLOWING MEMBERS WOULD BE PUBLIC.
	public:
		// FUNCTION SIGNATURES.
		void setEmpty();
		void createArmy(const char* country, double pow, int troops);
		void updateUnits(int troops);
		const char* checkNationality() const;
		int checkCapacity() const;
		double checkPower() const;
		bool isEmpty() const;
		bool isStrongerThan(const Army& army)const;
		
	};

	// FUNCTION SIGNATURES
	void battle(Army& arm1, Army& arm2);
	void displayDetails(const Army* armies, int size);

}

#endif // !SDDS_ARMY_H
