//***********************************************************************
// OOP244 Workshop 2: Dynamic Memory
// Filename:          Kingdom.cpp
// Date:	          2018/05/28
// Author:	          Sharan Shanmugaratnam
// Description:
// A workshop designed to help us with allocating memory at run-time 
// and deallocating that memory as soon as it is no longer required.
//***********************************************************************

#include <iostream>
#include "Kingdom.h"

using namespace std;
namespace sict {

	//Overloading the display function
	//
	void display(struct Kingdom a) {
		cout << a.m_name << ", population " << a.m_population << endl;
	}

	void display(Kingdom kingdom[], int count) {
		int i;
		int total = 0;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		for (i = 0; i < count; i++) {
			cout << i + 1 << "." << kingdom[i].m_name << ", " << "population " << kingdom[i].m_population << endl;
			total += kingdom[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << total<< endl;
		cout << "------------------------------" << endl;
	}
}
