//***********************************************************************
// OOP244 Milestone 5: The Product Hierarchy
// Filename:           Perishable.cpp
// Date:	             2018/08/01
// Author:	           Sharan Shanmugaratnam
//***********************************************************************

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Perishable.h"
#include "Date.h"

using namespace std;

namespace AMA {
  // Constructor with no arguments.
  // This constructor passes the file record tag for a perishable product (‘P’)
  // to the base class constructor and sets the current object to a safe empty state.
  //
  Perishable::Perishable() : Product('P') {

  }

  // Function inserts a comma into the file record and appends the expiry date
  // to the file record with an optional newline.
  //
  std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
    Product::store(file, false);
    file << ',';
    file << m_expiry;
    file << endl;

    return file;
  }

  // Function loads the expiry date from the file record using the read() function 
  // of the Date object and extracts a single character from the fstream object.
  //
  std::fstream& Perishable::load(std::fstream& file) {
    Product::load(file);
    file >> m_expiry;
    file.ignore();
    return file;
  }

  // Function does nothing if the current object is in an error or safe empty state,
  // otherwise inserts the expiry date into the ostream object and if linear is true,
  // adds the expiry date on the same line for an outcome.
  //
  std::ostream& Perishable::write(std::ostream& os, bool linear) const {
    os.fill(' '); // Need to fill with whitespace or defaults to '0'.
    Product::write(os, linear);

    if (isClear() && !isEmpty()) {
      if (linear == true) {
        m_expiry.write(os);
      }
      else {
        os << endl;
        os << " Expiry date: ";
        m_expiry.write(os);
      }
    }

    return os;
  }

  // Function validates base class object data and prompts for the expiry date to store 
  // in a temp Date object. If date object is also in an error state, it will store the
  // appropriate error message. If not in error state, function copy assigns the temp
  // Date object to the instance Date object. 
  //
  std::istream& Perishable::read(std::istream& is) {
    Date temp;
    Product::read(is);
    if (is.good()) {
      std::cout << " Expiry date (YYYY/MM/DD): ";
      temp.read(is);
      if (temp.bad() == true) {
        is.setstate(std::ios::failbit);
        switch (temp.errCode()) {
        case CIN_FAILED:
          message("Invalid Date Entry");
          break;
        case YEAR_ERROR:
          message("Invalid Year in Date Entry");
          break;
        case MON_ERROR:
          message("Invalid Month in Date Entry");
          break;
        case DAY_ERROR:
         message("Invalid Day in Date Entry");
          break;
        }
      }
      else {
        m_expiry = temp;
      }
    }
    return is;
  }

  // Function returns the expiry date for the perishable product.
  //
  const Date& Perishable::expiry() const {
    return m_expiry;
  }
}