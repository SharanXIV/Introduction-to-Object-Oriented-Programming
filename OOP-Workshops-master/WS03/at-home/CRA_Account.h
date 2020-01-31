//***********************************************************************
// OOP244 Workshop 3: Classes and Privacy
// Filename:          CRA_Account.h
// Date:	          2018/06/05
// Author:	          Sharan Shanmugaratnam
// Description:
// Learning to code	a class definition with private data members and
// public functions and code the logic for the member functions.
//***********************************************************************

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
	// Constants
	//
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	// Class
	//
	class CRA_Account {
		// Private members
		//
		char s_familyName[max_name_length + 1];
		char s_givenName[max_name_length + 1];
		int s_sin;
		int taxyears[max_yrs];
		double s_balance[max_yrs];
		int totYears;
		int sinArray[9];
		
		//Public members
		//
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
	};
}
#endif
