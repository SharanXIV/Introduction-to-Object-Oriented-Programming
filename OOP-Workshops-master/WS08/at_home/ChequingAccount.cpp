//***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// Filename:          ChequingAccount.cpp
// Date:	            2018/07/24
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to implement an abstract definition 
// of behavior for a specific type.
//***********************************************************************

#include "ChequingAccount.h"
using namespace std;

namespace sict {
  // Constructor initializes balance and transaction fee.
  //
  ChequingAccount::ChequingAccount(double balance, double trans, double month) :Account(balance) {
    if (trans > 0) {
      transFee = trans;
    }
    else {
      transFee = 0.0;
    }

    if (month > 0) {
      monthFee = month;
    }
    else {
      monthFee = 0.0;
    }
  }

  // Credits (add) an amount to the account balance and charges fee.
  // Returns bool indicating whether money was credited.
  //
  bool ChequingAccount::credit(double amount) {
    if (amount > 0) {
      Account::credit(amount);
      Account::debit(transFee);
      return true;
    }
    else {
      return false;
    }
  }

  // Debits (subtract) an amount from the account balance and charges fee.
  // Returns bool indicating whether money was debited.
  //
  bool ChequingAccount::debit(double amount) {
    if (amount > 0) {
      Account::debit(amount);
      Account::debit(transFee);
      return true;
    }
    else {
      return false;
    }
  }

  // monthEnd debits month end fee.
  //
  void ChequingAccount::monthEnd() {
    debit(monthFee);
  }

  // Display inserts account information into ostream os.
  //
  void ChequingAccount::display(std::ostream& os) const {
    std::cout << "Account type: Chequing" << std::endl;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << "Balance: $" << balance() << std::endl;
    std::cout << "Per Transaction Fee: " << transFee << std::endl;
    std::cout << "Monthly Fee: " << monthFee << std::endl;
    std::cout.unsetf(std::ios::fixed);
  }
}