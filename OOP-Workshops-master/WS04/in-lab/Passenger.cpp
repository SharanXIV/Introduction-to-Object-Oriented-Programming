//***********************************************************************
// OOP244 Workshop 4: Constructors
// Filename:          Passenger.cpp
// Date:	          2018/06/08
// Author:	          Sharan Shanmugaratnam
// Description:
// Learning to initialize the data within an object 
// of class type upon its creation.
//***********************************************************************

#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

// Default constructor.
//
sict::Passenger::Passenger() {
	*passName = '\0';
	*dest = '\0';
}

// Constructor with two parameters.
//
sict::Passenger::Passenger(const char* passengerName, const char* passengerDest) {
	if (passengerName != '\0' && passengerDest != '\0') {
		strncpy(passName, passengerName, max_size); // accept the client's data
		passName[max_size] = '\0';
		strncpy(dest, passengerDest, max_size);
		dest[max_size] = '\0';
	}
	else {
		*passName = '\0';
		*dest = '\0';
	}
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
		cout << passName << " - " << dest << endl;
	}
	else {
		cout << "No passenger!" << endl;
	}
}
