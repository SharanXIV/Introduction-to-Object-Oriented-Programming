//***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads
// Filename:          Fraction.cpp
// Date:	          2018/06/19
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to overload an operator as a member function
// of a class type, accessing the current object from within a member
// function and identify the lifetime of an object, including temp objects.
//***********************************************************************

#include <iostream>
#include "Fraction.h"
using namespace std;

namespace sict {
	// Default constructor.
	//
	Fraction::Fraction() {
		// Set empty state for default constructor.
		//
		numerator = -1;
		denominator = -1;
	}

	// Constructor with two parameters.
	//
	Fraction::Fraction(int n, int d) {
		if (n >= 0 && d >= 0) {
			numerator = n;
			denominator = d;
			reduce();
		}
		else {
			numerator = -1;
			denominator = -1;
		}
	}

	// Returns the greater value of the numerator and denominator.
	//
	int Fraction::max() const {
		return (numerator > denominator) ? numerator : denominator;
	}

	// Returns the lesser value of the numerator and denominator.
	//
	int Fraction::min() const {
		return (numerator > denominator) ? denominator : numerator;
	}

	// Returns the greatest common divisor of numerator and denominator.
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	void Fraction::reduce() {
		int g_c_d = gcd();
		numerator = numerator / g_c_d;
		denominator = denominator / g_c_d;
	}

	void Fraction::display() const {
		if (!isEmpty()) {
			if (denominator == 1) {
				cout << numerator;
			}
			else {
				cout << numerator << "/" << denominator;
			}
		}
		else {
			cout << "no fraction stored";
		}
	}

	bool Fraction::isEmpty() const {
		return (denominator <= -1);
	}

	// Overloaded Member Operator +.
	//
	Fraction Fraction::operator+(const Fraction& rhs) {
		Fraction Result;
		if (!isEmpty() || !rhs.isEmpty()) {
			Result.numerator = (numerator*rhs.denominator) + (denominator*rhs.numerator);
			Result.denominator = denominator * rhs.denominator;
			Result.reduce();
		}
		else {
			Result = Fraction(); // Sets empty state.
		}
		return Result;
	}

	// Overloaded Member Operator *.
	//
	Fraction Fraction::operator*(const Fraction& rhs) {
		Fraction Result;
		if (!isEmpty() || !rhs.isEmpty()) {
			Result.numerator = numerator*rhs.numerator;
			Result.denominator = denominator * rhs.denominator;
			Result.reduce();
		}
		else {
			Result = Fraction(); // Sets empty state.
		}
		return Result;
	}

	// Overloaded Member Operator ==.
	//
	bool Fraction::operator==(const Fraction& rhs) const {
		bool Result = false;
		if (!isEmpty() || !rhs.isEmpty()) {
			if (numerator == rhs.numerator && denominator == rhs.denominator) {
				Result = true;
			}
		}
		else {
			Result = false;
		}
		return Result;
	}

	// Overloaded Member Operator !=.
	//
	bool Fraction::operator!=(const Fraction& rhs) const {
		bool Result = false;
		if (!isEmpty() || !rhs.isEmpty()) {
			if (!(this->operator==(rhs))) {
				Result = true;
			}
		}
		else {
			Result = false;
		}
		return Result;
	}

	// Overloaded Member Operator +=.
	//
	Fraction& Fraction::operator+=(const Fraction& rhs) {
		if (!isEmpty() || !rhs.isEmpty()) {
			numerator = (numerator*rhs.denominator) + (denominator*rhs.numerator);
			denominator = denominator * rhs.denominator;
			reduce();
		}
		else {
			*this = Fraction(); // Sets empty state.
		}
		return *this;
	}
}


