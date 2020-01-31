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
	void display(struct Kingdom a) {
		cout << a.m_name << ", population " << a.m_population << endl;
	}
}
 