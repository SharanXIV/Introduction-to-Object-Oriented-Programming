//***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads
// Filename:          Fraction.h
// Date:	          2018/06/19
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to overload an operator as a member function
// of a class type, accessing the current object from within a member
// function and identify the lifetime of an object, including temp objects.
//***********************************************************************

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {
	class Fraction {
		// Private members
		//
		int numerator;
		int denominator;
		int min() const;
		int max() const;
		void reduce();
		int gcd() const;
	public:
		// Public members
		//
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;

		Fraction operator+(const Fraction&);
		Fraction operator*(const Fraction&);
		bool operator==(const Fraction&) const;
		bool operator!=(const Fraction&) const;
		Fraction& operator+=(const Fraction&);
	};
}
#endif