//***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// Filename:          SavingsAccount.h
// Date:	            2018/07/20
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to implement an abstract definition 
// of behavior for a specific type.
//***********************************************************************

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
  class SavingsAccount : public Account {
    // Private Members
    //
    double intRate;

    // Public Members
    //
  public:
    SavingsAccount(double, double);
    void monthEnd();
    void display(std::ostream&) const;

  };
}
#endif
