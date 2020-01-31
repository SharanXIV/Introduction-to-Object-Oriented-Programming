//***********************************************************************
// OOP244 Workshop 6: Class with a Resource
// Filename:          Contact.h
// Date:	            2018/07/06
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to design and code a class type that
// accesses a resource.
//***********************************************************************

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
  const int maxname = 20;

  class Contact {
    // Private members
    //
    char name[maxname];
    long long* phoneNum;
    int numbers;

  public:
    // Public members
    //
    Contact();
    Contact(const char* names, const long long* phoneNums, int nums);
    ~Contact();

    bool isEmpty() const;
    void display() const;
  };
}

#endif