//***********************************************************************
// OOP244 Workshop 6: Class with a Resource
// Filename:          Contact.cpp
// Date:	            2018/07/11
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to design and code a class type that
// accesses a resource.
//***********************************************************************

#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;

namespace sict {
  // Default constructor.
  //
  Contact::Contact() {
    // Set empty state for default constructor.
    //
    name[0] = '\0';
    phoneNum = 0;
    numbers = 0;
  }

  //Constructor with 3 parameters.
  //
  Contact::Contact(const char* names, const long long* phoneNums, int nums) {
    if (!(names == NULL || names[0] == '\0' || strcmp(names, "") == 0)) {
      strncpy(name, names, 20);
      name[maxname - 1] = '\0';

      long long* validPhone = nullptr;
      validPhone = new long long[nums];
      int count = 0;

      for (int i = 0; i < nums; i++) {
        int countryCode = phoneNums[i] / 10000000000;
        int areaCode = (phoneNums[i] % 10000000000) / 10000000;
        int number = phoneNums[i] % 10000000;

        if ((countryCode > 0 && countryCode < 100) && (areaCode > 99 && areaCode < 1000) && (number > 999999 && number < 10000000)) {
          validPhone[count] = phoneNums[i];
          count++;
        }
      }

      numbers = count;
      phoneNum = validPhone;
    }
    else {
      name[0] = '\0';
      phoneNum = 0;
      numbers = 0;
    }
  }

  //Copy Constructor
  //
  Contact::Contact(const Contact& contact) {
    strncpy(name, contact.name, maxname - 1);
    name[maxname - 1] = '\0';
    numbers = contact.numbers;

    if (contact.phoneNum != NULL) {
      phoneNum = new long long[numbers];
      for (int i = 0; i < numbers; i++) {
        phoneNum[i] = contact.phoneNum[i];
      }
    }
    else {
      phoneNum = nullptr;
    }
  }

  //Copy Assignment Operator
  //
  Contact& Contact::operator=(const Contact& contact) {
    if (this != &contact) {
      strncpy(name, contact.name, maxname - 1);
      name[maxname - 1] = '\0';
      numbers = contact.numbers;
      delete[] phoneNum;

      if (contact.phoneNum != nullptr) {
        phoneNum = new long long[numbers];
        for (int i = 0; i < numbers; i++) {
          phoneNum[i] = contact.phoneNum[i];
        }
      }
      else {
        phoneNum = NULL;
      }
    }
    return *this;
  }

  //Overloaded += Operator
  //
  Contact& Contact::operator+=(const long long newPhone) {
    int countryCode = newPhone / 10000000000;
    int areaCode = (newPhone % 10000000000) / 10000000;
    int number = newPhone % 10000000;
    if ((countryCode > 0 && countryCode < 100) && (areaCode > 99 && areaCode < 1000) && (number > 999999 && number < 10000000)) {
      long long* tempPhone = nullptr;
      tempPhone = new long long[numbers + 1];
      
      for (int i = 0; i < numbers + 1; i++) {
        if (phoneNum != nullptr) {
          tempPhone[i] = phoneNum[i];
        }
      }

      tempPhone[numbers] = newPhone;
      Contact temp(name, tempPhone, numbers + 1);
      *this = temp;
    }
    return *this;
  }

  // Destructor.
  //
  Contact::~Contact() {
    //delete[] phoneNum;
  }

  bool Contact::isEmpty() const {
    return ((name == NULL || name[0] == '\0' || strcmp(name, "") == 0));
  }

  void Contact::display() const {
    if (!isEmpty()) {
      cout << name << endl;
      for (int i = 0; i < numbers; i++) {
        int countryCode = phoneNum[i] / 10000000000;
        int areaCode = (phoneNum[i] % 10000000000) / 10000000;
        int number = phoneNum[i] % 10000000;
        int firstPart = number / 10000;
        int secondPart = number % 10000;

        cout << "(+" << countryCode << ") " << areaCode << " " << firstPart << "-";
        cout.width(4);
        cout.fill('0');
        cout << secondPart << endl;
      }
    }
    else {
      cout << "Empty contact!" << endl;
    }
  }
}