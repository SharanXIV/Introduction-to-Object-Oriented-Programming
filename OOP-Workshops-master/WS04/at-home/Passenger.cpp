//***********************************************************************
// OOP244 Workshop 4: Constructors
// Filename:          Passenger.cpp
// Date:	          2018/06/12
// Author:	          Sharan Shanmugaratnam
// Description:
// Learning to initialize the data within an object 
// of class type upon its creation.
//***********************************************************************

#include <iostream>
#include <cstring>
#include <cstdio>
#include "Passenger.h"

using namespace std;

// Default constructor.
//
sict::Passenger::Passenger() {
	// Set empty state for default constructor.
	//
	*passName = '\0';
	*dest = '\0';
	yearDep = 0;
	monthDep = 0;
	dayDep = 0;
}

// Constructor with two parameters.
//
sict::Passenger::Passenger(const char* passengerName, const char* passengerDest) {
	if (passengerName != '\0' && passengerDest != '\0') {
		strncpy(passName, passengerName, max_size); // accept the client's data
		passName[max_size] = '\0';
		strncpy(dest, passengerDest, max_size);
		dest[max_size] = '\0';

		//Setting date to default July 1st, 2017
		//
		yearDep = 2017;
		monthDep = 7;
		dayDep = 1;
	}
	else {
		// Set empty state.
		//
		Passenger();
	}
}

// Constructor with five parameters.
//
sict::Passenger::Passenger(const char* passengerName, const char* passengerDest, int year, int month, int day) {
	if ((passengerName != nullptr) && (strlen(passengerName) > 0) && (passengerDest != nullptr) && (strlen(passengerDest) > 0) && (year >= 2017) && (year <= 2020) && (month >= 1) && (month <= 12) && (day >= 1) && (day <= 31)) {
		strncpy(passName, passengerName, max_size); // accept the client's data
		passName[max_size] = '\0';
		strncpy(dest, passengerDest, max_size);
		dest[max_size] = '\0';

		//Setting date to accepted values
		//
		yearDep = year;
		monthDep = month;
		dayDep = day;
	}
	else {
		// Set empty state.
		//
		*passName = '\0';
		*dest = '\0';
		yearDep = 0;
		monthDep = 0;
		dayDep = 0;
	}
}

bool sict::Passenger::canTravelWith(const Passenger& passenger) const {
	bool match = false;
	//Checks whether two passengers have the same destination and date.
	//
	if ((strcmp(passenger.dest, dest) == 0) && (passenger.yearDep == yearDep) && (passenger.monthDep == monthDep) && (passenger.dayDep == dayDep)) {
		match = true;
	}

	return match;
}

const char* sict::Passenger::name() const {
	return passName;
}

// Checks whether instance variables are empty or not.
//
bool sict::Passenger::isEmpty() const {
	return (*passName == '\0' || *dest == '\0');
}

// Displays passenger and destination information.
//
void sict::Passenger::display() const {
	if (!isEmpty()) {
		cout << passName << " - " << dest << " on " << yearDep << "/";
		if (monthDep < 10) {
			cout << "0" << monthDep << "/";
		}
		else {
			cout << monthDep << "/";
		}
		if (dayDep < 10) {
			cout << "0" << dayDep << endl;
		}
		else {
			cout << dayDep << endl;
		}
	}
	else {
		cout << "No passenger!" << endl;
	}
}
