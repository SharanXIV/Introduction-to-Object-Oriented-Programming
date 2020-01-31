/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// 2018/06/01
// MingXuan Li
// 106932171
**********************************************************/

#include "CRA_Account.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sict {

	//this function will gave the value for the year and account
	void CRA_Account::set(const int vyear, const double balance) {
		if (sin != 0) {
			//x is the size for arrary of year and account
			if (x < max_yrs) {
				//save year's value
				if (vyear != 0) {
					year[x] = vyear;
				}
				//save account's value
				if (balance != 0) {
					account[x] = balance;
				}
				x++;
			}
		}
	}

	//this function will gave the value for family name, given name and social insurance number 
	void CRA_Account::set(const char* familyName, const char* givenName, int sin_) {
		int check;
		int all = 0;
		//check sin has 9 numbers or not
		if (sin_ > min_sin && sin_ < max_sin) {
			int sin2 = sin_;
			int j;
			//to get each single number
			for (j = 8; j >= 0; j--) {
				//if the number is second or fourth or Sixth or Eighth number
				if (j % 2 != 0) {
					// let this number *2
					number[j] = (sin2 % 10) * 2;
					// If this number is two digits, add each number
					if (number[j] > 9) {

						all += (number[j] % 10) + (number[j] / 10);
					}
					// if this number is single number, just add this number
					else {
						all += number[j];
					}
				}
				//this is the last one number of sin
				else if (j == 8) {
					check = sin2 % 10;
				}
				//else the number is first, third or fifth number
				else {
					number[j] = sin2 % 10;
					all += number[j];
				}
				sin2 /= 10;
			}

			//use 10 - int all's single digits, if == int check that is the last number of sin, it is right
			if (((10 - all % 10) == check) && (familyName != nullptr) && (givenName != nullptr)) {
				strcpy(Fname, familyName);
				Fname[max_name_length + 1] = '\0';
				strcpy(Gname, givenName);
				Gname[max_name_length + 1] = '\0';
				sin = sin_;
				x = 0;//x is the size for arrary of year and account
			}
			else {

				sin = 0;
				x = 0;

			}
		}
		else {
			sin = 0;
			x = 0;

		}
	}

	// this function will check family name and gaven name and sin is empty or not, it also check sin has 9 number or not
	bool CRA_Account::isEmpty() const {
		if (sin == 0 || sin > max_sin || sin < min_sin || Fname[0] == '\0' || Gname[0] == '\0') {
			return true;
		}
		else {
			return false;
		}

	}

	// this function will display all the informations
	void CRA_Account::display() const {
		if (sin != 0) {
			int i;
			cout << "Family Name: " << Fname << endl;
			cout << "Given Name : " << Gname << endl;
			cout << "CRA Account: " << sin << endl;
			// to display year and account
			for (i = 0; i < x; i++) {
				cout.precision(2);
				//check account more than 2 or less than -2 or between 2 and -2.
				if (account[i] > 2) {
					cout.setf(ios::fixed);
					cout << "Year (" << year[i] << ") balance owing: " << account[i] << endl;

				}
				if (account[i] < -2) {
					cout.setf(ios::fixed);
					cout << "Year (" << year[i] << ") refund due: " << -(account[i]) << endl;

				}
				if (account[i] > -2 && account[i] < 2) {
					cout << "Year (" << year[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty! " << endl;
		}

	}

}
