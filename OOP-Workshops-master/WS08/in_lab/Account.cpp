//***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// Filename:          Account.cpp
// Date:	            2018/07/20
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to implement an abstract definition 
// of behavior for a specific type.
//***********************************************************************

#include <iostream>
#include "iAccount.h"
#include "Account.h"

using namespace std;

namespace sict {

  double Account::balance() const {
    return accBalance;
  }

  // Constructor with 1 argument.
  //
  Account::Account(double balance) {
    if (balance > 0) {
      accBalance = balance;
    }
    else {
      balance = 0;
    }
  }

  // Credits to balance.
  //
  bool Account::credit(double balance) {
    if (balance > 0) {
      accBalance += balance;
      return true;
    }
    else {
      return false;
    }
  }

  // Debits from balance.
  //
  bool Account::debit(double balance) {
    if (balance > 0) {
      accBalance -= balance;
      return true;
    }
    else {
      return false;
    }
  }

}