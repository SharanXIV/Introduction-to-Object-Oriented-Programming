//***********************************************************************
// OOP244 Milestone 3: The Product Class
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
    delete[] errorMsg;
  }

  // This function clears any message stored by the current object and initializes the object to a safe empty state.
  //
  void ErrorState::clear() {
    delete[] errorMsg;
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

    delete[] errorMsg;
    errorMsg = new char[len + 1];

    strncpy(errorMsg, str, len);
    errorMsg[len + 1] = '\0';
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

