//***********************************************************************
// OOP244 Workshop 2: Dynamic Memory
// Filename:          w2_at_home.cpp
// Date:	          2018/05/28
// Author:	          Sharan Shanmugaratnam
// Description:
// A workshop designed to help us with allocating memory at run-time 
// and deallocating that memory as soon as it is no longer required.
//***********************************************************************

#include <iostream>
#include <cstring>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(Kingdom&);

int main() {
	int count = 0; // the number of kingdoms in the array

	// Declaring the pKingdom pointer here
	//
	Kingdom* pKingdom = nullptr;


	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	// Allocating dynamic memory here for the pKingdom pointer
	//
	pKingdom = new Kingdom[count];

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		
		// Runs the read function to get user input
		//
		read(pKingdom[i]);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st kingdom entered is" << endl
		<< "------------------------------" << endl;
	display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	// Expanding the array of Kingdoms by 1 element
	// Allocate dynamic memory for count + 1 Kingdoms
	//
	Kingdom* pKingdoms = nullptr;
	pKingdoms = new Kingdom[count + 1];

	// Copying elements from original array into this newly allocated array
	//
	for (int i = 0; i < count; i++) {
		pKingdoms[i] = pKingdom[i];
	}

	// Deallocating the dynamic memory for the original array
	//
	delete[] pKingdom;

	// Copying the address of the newly allocated array into pKingdom pointer
	//
	pKingdom = pKingdoms;

	// add the new Kingdom
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Kingdom #" << count + 1 << ": " << endl;
	
	// Accepting input for the new element in the array
	//
	read(pKingdom[count]);
	count++;
	cout << "==========\n" << endl;

	// testing that the overload of "display(...)" works
	display(pKingdom, count);
	cout << endl;

	// Deallocating the dynamic memory for the second array
	//
	delete[] pKingdoms;
	
	return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {
	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
