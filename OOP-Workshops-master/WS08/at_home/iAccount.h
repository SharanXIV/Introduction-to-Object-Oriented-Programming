//***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// Filename:          iAccount.h
// Date:	            2018/07/20
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to implement an abstract definition 
// of behavior for a specific type.
//***********************************************************************

#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__

#include <iostream>

namespace sict {
  class iAccount {
    // Public Members
    //
  public:
    virtual ~iAccount() = 0;
    virtual bool credit(double) = 0;
    virtual bool debit(double) = 0;
    virtual void monthEnd() = 0;
    virtual void display(std::ostream&) const = 0;
  };

  iAccount* CreateAccount(const char*, double);
}

#endif

