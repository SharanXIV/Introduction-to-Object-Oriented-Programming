//***********************************************************************
// OOP244 Workshop 3: Classes and Privacy
// Filename:          CRA_Account.h
// Date:	          2018/06/01
// Author:	          Sharan Shanmugaratnam
// Description:
// Learning to code	a class definition with private data members and
// public functions and code the logic for the member functions.
//***********************************************************************

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {
		char familyName[max_name_length + 1];
		char givenName[max_name_length + 1];
		int sin;
	public:
		void set(const char*, const char*, int);
		bool isEmpty() const;
		void display() const;
	};
}
#endif
