//***********************************************************************
// OOP244 Workshop 3: Classes and Privacy
// Filename:          CRA_Account.cpp
// Date:	          2018/06/05
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

// Overloaded set function with two parameters, this function stores year and balance in the object.
//
void CRA_Account::set(int year, double balance) {
	if (!isEmpty()) { // Ensures that SIN and names are not empty.
		if (totYears < max_yrs) {
			if (year != 0) {
				taxyears[totYears] = year;
			}
			if (balance != 0) {
				s_balance[totYears] = balance;
			}
			totYears++;
		}
	}
}

// Overloaded set function with three parameters.
//
void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
	int checkDigit; // The last digit in the SIN.
	int sum = 0;
	if ((sin <= max_sin) && (sin >= min_sin)) { //checking if SIN is between 100000000 and 999999999 and names are not empty.
		int temp = sin;
		for (int i = 8; i >= 0; i--) { //Goes through SIN backwards to allocate each digit into array.
			if (i % 2 != 0) { // When at the odd digit.
				sinArray[i] = (temp % 10) * 2;
				if (sinArray[i] > 9) { // If the element is a double digit number we must add the digits together.
					sum += (sinArray[i] / 10) + (sinArray[i] % 10);
				}
				else { // If single digit number, it gets added to the sum.
					sum += sinArray[i];
				}
			}
			else if (i == 8) { // When the index is at the 9th digit of the SIN.
				checkDigit = temp % 10; // Make the last digit the check digit.
			}
			else { // When at the even digit.
				sinArray[i] = temp % 10;
				sum += sinArray[i];
			}
			temp /= 10; // Truncates the last digit.
		}

		if (((10 - sum % 10) == checkDigit) && isEmpty()) { // Ensures the check digit matches and also makes sure SIN/names aren't blank.
			strncpy(s_familyName, familyName, max_name_length); // accept the client's data
			s_familyName[max_name_length] = '\0';
			strncpy(s_givenName, givenName, max_name_length);
			s_givenName[max_name_length] = '\0';
			s_sin = sin;
			totYears = 0; // Initializes the number of years for which data is stored to 0.
		}

		else {
			*s_familyName = '\0'; // Ignore the client's data, set an empty state.
			*s_givenName = '\0';
			s_sin = 0;
			totYears = 0;
		}
	}
	else {
		*s_familyName = '\0'; // Ignore the client's data, set an empty state.
		*s_givenName = '\0';
		s_sin = 0;
		totYears = 0;
	}
}

// Checks if SIN is empty or either name's first character array element is a null.
//
bool CRA_Account::isEmpty() const {
	return ((s_sin == 0) || (s_familyName[0] == '\0') || (s_givenName[0] == '\0')); 
}

// Displays all the inputted information and balances.
//
void CRA_Account::display() const {
	if (!isEmpty()) {
		cout << "Family Name: " << s_familyName << endl;
		cout << "Given Name: " << s_givenName << endl;
		cout << "CRA Account: " << s_sin << endl;

		for (int i = 0; i < totYears; i++) {
			cout.precision(2); // Printed amount has exactly two digits for general format and two decimal points for fixed format.
			if (s_balance[i] > 2) { // Amount still owing.
				cout.setf(ios::fixed);
				cout << "Year (" << taxyears[i] << ") balance owing: " << s_balance[i] << endl;
				cout.unsetf(ios::fixed);
			}
			if (s_balance[i] < -2) { // Amount due to be refunded.
				cout.setf(ios::fixed);
				cout << "Year (" << taxyears[i] << ") refund due: " << -(s_balance[i]) << endl;
				cout.unsetf(ios::fixed);
			}
			if ((s_balance[i] > -2) && (s_balance[i] < 2)) { // If amount owing or due is within two dollars, it is neglected.
				cout << "Year (" << taxyears[i] << ") No balance owing or refund due!" << endl;
			}
		}
	}
	else {
		cout << "Account object is empty!" << endl;
	}
}