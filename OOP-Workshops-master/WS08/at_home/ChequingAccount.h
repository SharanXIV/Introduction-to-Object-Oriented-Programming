//***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// Filename:          ChequingAccount.h
// Date:	            2018/07/24
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to implement an abstract definition 
// of behavior for a specific type.
//***********************************************************************

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount:public Account {
    // Private Members
    //
    double transFee;
    double monthFee;

    // Public Members
    //
		public:
      ChequingAccount(double, double, double);
      bool credit(double);
      bool debit(double);
      void monthEnd();
      void display(std::ostream&) const;
	};
}

#endif
