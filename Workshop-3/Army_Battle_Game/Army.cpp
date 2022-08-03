
#define _CRT_SECURE_NO_WARNINGS

// INCLUDING HEADER FILES.
#include<cstring>
#include<iostream>
#include"Army.h"

using namespace std;

namespace sdds
{

	// FUNCTION DEFINATIONS.

	// FUNCTION MEMBERS.
	void Army::setEmpty()
	{

		m_armNationality[0] = '\0';
		m_armUnits = 0;

	}

	void Army::createArmy(const char* country, double pow, int troops)
	{

		// TO VALIDARE IF THE VALUE PROVIDED BY THE CLIENT CODE IS IN PROPER RANGE.
		if (country != nullptr && strlen(country) > 0 && pow > 0 && troops > 0)
		{

			// ASSIGNING VALUES PROVIDED BY THE CLIENT CODE.
			if ((strlen(country) + 1) > MAX_NAME_LEN)
			{

				strncpy(m_armNationality, country, MAX_NAME_LEN);

			}
			else
			{

				strcpy(m_armNationality, country);

			}

			m_armUnits = troops;
			m_armPower = pow;

		}
		// THIS WILL SET THE VARIABLES TO EMPTY STATE IF THE VALUE PROVIDED BY THE CLIENT CODE IS INVALID.
		else
		{

			setEmpty();

		}

	}

	void Army::updateUnits(int troops)
	{

		// FOR EVERY TROOPS GAINED THE UNITS OF THE ARMY WOULD BE INCREMENTED ALONG WITH THE INCREMENT 25% OF THE POWER OF THE ARMY.
		m_armUnits += troops;
		m_armPower += 0.25 * troops;

	}

	const char* Army::checkNationality() const
	{

		return m_armNationality;

	}

	int Army::checkCapacity() const
	{

		return m_armUnits;

	}

	double Army::checkPower() const
	{

		// THIS WILL SET THE PRECISION OF THE OUTPUT FLOAT VALUE TO 1 DIGIT AFTER DECIMAL NUMBER.
		cout.setf(ios::fixed);
		cout.precision(1);

		return m_armPower;

	}

	bool Army::isEmpty() const
	{

		return(m_armNationality[0] == '\0' && m_armUnits == 0);

	}

	bool Army::isStrongerThan(const Army& army)const
	{

		return (m_armPower > army.m_armPower);

	}

	// STAND ALONE FUNCTIONS.
	void battle(Army& arm1, Army& arm2)
	{

		if (!(arm1.isEmpty() && arm2.isEmpty()))
		{

			// IF THE ARM1 IS STRONGER, THIS WILL BE EXECUTED.
			if (arm1.isStrongerThan(arm2))
			{

				cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", " << arm1.checkNationality() << " is victorious!" << endl;
				arm2.updateUnits(int(-arm2.checkCapacity() * 0.5));

			}
			// IF THE ARM2 IS STRONGER, THIS WILL BE EXECUTED.
			else
			{

				cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", " << arm2.checkNationality() << " is victorious!" << endl;
				arm1.updateUnits(int(-arm2.checkCapacity() * 0.5));

			}

		}

	}

	void displayDetails(const Army* armies, int size)
	{

		cout << "Armies reporting to battle: " << endl;

		for (int i = 0; i < size; i++)
		{

			if (!(armies[i].isEmpty()))
			{

				cout << "Nationality: " << armies[i].checkNationality() << ", Units Count: " << armies[i].checkCapacity() << ", Power left: " << armies[i].checkPower() << endl;

			}

		}

	}

}