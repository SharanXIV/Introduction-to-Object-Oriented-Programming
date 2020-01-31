//***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// Filename:          Allocator.cpp
// Date:	            2018/07/20
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to implement an abstract definition 
// of behavior for a specific type.
//***********************************************************************

#include "SavingsAccount.h" 

namespace sict {

  // Destructor
  iAccount::~iAccount() {
  }


  // Interest rate
  //
  const double rate = 0.05;

  // Allocator function
  //
  iAccount* CreateAccount(const char* type, double balance) {
    iAccount* account = nullptr;

    if (type[0] == 's' || type[0] == 'S') {
      account = new SavingsAccount(balance, rate);
    }

    return account;
  }

}