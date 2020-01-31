//***********************************************************************
// OOP244 Milestone 5: The Product Hierarchy
// Filename:           ErrorState.cpp
// Date:	             2018/07/28
// Author:	           Sharan Shanmugaratnam
//***********************************************************************

#include <iostream>
#include <cstring>
#include "ErrorState.h"

namespace AMA {

  // Default Constructor
  //
  ErrorState::ErrorState() {
    errorMsg = nullptr;
  }

  // Constructor with one argument.
  //
  ErrorState::ErrorState(const char* errMsg) {
    errorMsg = nullptr;
    ErrorState::message(errMsg);
  }

  // Destructor
  //
  ErrorState::~ErrorState() {
 //   delete[] errorMsg;
 //   errorMsg = nullptr;
  }

  // This function clears any message stored by the current object and initializes the object to a safe empty state.
  //
  void ErrorState::clear() {
    errorMsg = nullptr;
  }

  // This query reports returns true if the current object is in a safe empty state.
  //
  bool ErrorState::isClear() const {
    return errorMsg == nullptr;
  }

  // This function stores a copy of the C-style string pointed to by str.
  //
  void ErrorState::message(const char* str) {
    int len = strlen(str);

    errorMsg = new char[len];

    strncpy(errorMsg, str, len);
    errorMsg[len] = '\0';
  }

  // This query returns the address of the message stored in the current object.
  //
  const char* ErrorState::message() const {
    return errorMsg;
  }

  // Overloaded '<<' operator.
  //
  std::ostream& operator<<(std::ostream& os, const ErrorState& es) {
    if (es.message() == nullptr) {
      return os;
    }
    else {
      os << es.message();
      return os;
    }
  }
}

