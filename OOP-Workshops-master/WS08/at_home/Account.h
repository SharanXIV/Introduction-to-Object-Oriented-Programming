//***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// Filename:          Account.h
// Date:	            2018/07/20
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to implement an abstract definition 
// of behavior for a specific type.
//***********************************************************************

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
  class Account : public iAccount{
    // Private Members
    //
    double accBalance;

	protected:
    // Protected Members
    //
    double balance() const;

	public:
    // Public Members
    //
    Account(double);
    bool credit(double);
    bool debit(double);
	};

  iAccount* CreateAccount(const char*, double);
}

#endif
