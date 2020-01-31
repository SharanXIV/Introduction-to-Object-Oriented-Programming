/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
// 2018/06/01
// MingXuan Li
// 106932171
**********************************************************/
#pragma once

#ifndef sict_CRA_ACCOUNT_H
#define sict_CRA_ACCOUNT_H


namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {
		char Fname[max_name_length + 1];
		char Gname[max_name_length + 1];
		int year[max_yrs];
		double account[max_yrs];
		int sin;
		int x;//x is the size for arrary of year and account
		int number[9];
	public:
		void set(const int, const double);
		void set(const char*, const char*, int);
		bool isEmpty() const;
		void display() const;
	};

}

#endif