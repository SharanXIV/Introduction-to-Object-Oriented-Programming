//***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// Filename:          SavingsAccount.cpp
// Date:	            2018/07/20
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to implement an abstract definition 
// of behavior for a specific type.
//***********************************************************************

#include <iostream>
#include "SavingsAccount.h"

namespace sict {
  
  // Constructor with 2 arguments.
  //
  SavingsAccount::SavingsAccount(double balance, double rate) : Account(balance) {
    if (rate > 0) {
      intRate = rate;
    }
    else {
      intRate = 0.0;
    }
  }

  void SavingsAccount::monthEnd() {
    double interest = intRate * balance();
    credit(interest);
  }

  // Display function.
  //
  void SavingsAccount::display(std::ostream& os) const {
    std::cout << "Account type: Savings" << std::endl;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << "Balance: $" << balance() << std::endl;
    std::cout << "Interest Rate (%): " << intRate * 100 << std::endl;
    std::cout.unsetf(std::ios::fixed);
  }
}