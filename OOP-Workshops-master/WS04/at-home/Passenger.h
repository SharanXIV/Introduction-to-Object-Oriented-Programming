//***********************************************************************
// OOP244 Workshop 4: Constructors
// Filename:          Passenger.h
// Date:	          2018/06/12
// Author:	          Sharan Shanmugaratnam
// Description:
// Learning to initialize the data within an object 
// of class type upon its creation.
//***********************************************************************

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict {
	const int max_size = 31;

	class Passenger {
		// Private members
		//
		char passName[max_size + 1];
		char dest[max_size + 1];
		int yearDep;
		int monthDep;
		int dayDep;

		// Public members
		//
	public:
		Passenger();
		Passenger(const char* passengerName, const char* passengerDest);
		Passenger(const char* passengerName, const char* passengerDest, int year, int month, int day);
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
		bool isEmpty() const;
		void display() const;
	};
}

#endif