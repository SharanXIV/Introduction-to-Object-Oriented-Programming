//***********************************************************************
// OOP244 Workshop 3: Classes and Privacy
// Filename:          CRA_Account.cpp
// Date:	          2018/06/01
// Author:	          Sharan Shanmugaratnam
// Description:
// Learning to code	a class definition with private data members and
// public functions and code the logic for the member functions.
//***********************************************************************

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;
using namespace sict;


void CRA_Account::set(const char* fn, const char* gn, int sn) {

	if ((sn <= max_sin) && (sn >= min_sin)) { //checking if SIN is between 100000000 and 999999999
		strncpy(familyName, fn, max_name_length); // accept the client's data
		familyName[max_name_length] = '\0';
		strncpy(givenName, gn, max_name_length);
		givenName[max_name_length] = '\0';
		sin = sn;
	}
	else
		sin = 0; // ignore the client's data, set an empty state
}

bool CRA_Account::isEmpty() const {
	return (sin == 0);
}

void CRA_Account::display() const {
	if (!isEmpty()) {
		cout << "Family Name: " << familyName << endl;
		cout << "Given Name: " << givenName << endl;
		cout << "CRA Account: " << sin << endl;
	}
	else {
		cout << "Account object is empty!" << endl;
	}
}