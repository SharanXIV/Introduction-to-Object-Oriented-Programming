//***********************************************************************
// OOP244 Milestone 5: The Product Hierarchy
// Filename:           ErrorState.h
// Date:	             2018/07/28
// Author:	           Sharan Shanmugaratnam
//***********************************************************************

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

namespace AMA {
  class ErrorState {
    // Private Members
    //
    char* errorMsg;

    // Public Members
    //
  public:
    ErrorState();
    ErrorState(const char* errorMessage);
    ErrorState(const ErrorState& em) = delete;

    ErrorState& operator=(const ErrorState& em) = delete;
    virtual ~ErrorState();
    void clear();
    bool isClear() const;
    void message(const char* str);
    const char* message()const;
  };

  // Helper Functions
  //
  std::ostream& operator<<(std::ostream& os, const ErrorState& es);

}

#endif