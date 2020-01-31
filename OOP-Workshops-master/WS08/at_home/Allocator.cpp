//***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// Filename:          Allocator.cpp
// Date:	            2018/07/24
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to implement an abstract definition 
// of behavior for a specific type.
//***********************************************************************

#include "SavingsAccount.h" 
#include "ChequingAccount.h" 

namespace sict {
  // Define interest rates.
  //
  double interestRate = 0.05;
  double transactionFee = 0.50;
  double monthlyFee = 2.00;

  // Destructor
  //
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
    else if (type[0] == 'c' || type[0] == 'C') {
      account = new ChequingAccount(balance, transactionFee, monthlyFee);
    }

    return account;
  }

}