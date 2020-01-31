//***********************************************************************
// OOP244 Workshop 9: Function Templates
// Filename:          Data.h
// Date:	            2018/07/27
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to you are to define a global function 
// in type-generic form.
//***********************************************************************

#ifndef SICT_DATA_H
#define SICT_DATA_H

#include <iostream>
#include <cstring>

using namespace std;

namespace sict {
  // These numbers define 
  // a) the range of data we expect to see in this workshop
  //    0 to 1 billion
  //    use them in the min and max function
  // b) the output column width for a single data field

  const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
  const int SMALLEST_NUMBER = 0;
  const int COLUMN_WIDTH = 15;

  // max returns the largest item in data
  //
  template <class T>
  T max(const T* data, int n) {
    T maxData = SMALLEST_NUMBER;

    for (int i = 0; i < n; i++) {
      if (maxData < data[i]) {
        maxData = data[i];
      }
    }

    return maxData;
  }

  // min returns the smallest item in data
  //
  template <class T>
  T min(const T* data, int n) {
    T minData = LARGEST_NUMBER;

    for (int i = 0; i < n; i++) {
      if (minData > data[i]) {
        minData = data[i];
      }
    }

    return minData;
  }

  // sum returns the sum of n items in data
  //    
  template <class T>
  T sum(const T* data, int n) {
    T sumData = 0;

    for (int i = 0; i < n; i++) {
      sumData += data[i];
    }

    return sumData;
  }

  // average returns the average of n items in data
  //
  template <class T>
  double average(const T* data, int n) {
    return (sum(data, n) / n);
  }

  // read extracts n items from input and stores them in data
  // - the items are comma separated
  // - this function assumes that a comma exists at the next field to be read
  // - for example: ,data1, data2,data3, ...., datan
  //
  template <class T>
  bool read(std::istream& input, T* data, int n) {
    for (int i = 0; i < n; i++) {
      input.ignore(256, ',');
      input >> data[i];
    }

    return true;
  }

  // display inserts n items of data into std::cout
  //
  template <class T>
  void display(const char* name, const T* data, int n) {
    std::cout.width(20);
    std::cout << std::right << name;

    for (int i = 0; i < n; i++) {
      std::cout.width(15);
      std::cout << data[i];
    }

    std::cout << std::endl;
  }

  // readRow replaced with a single templated function of the same name
  //
  template <class T>
  bool readRow(std::istream& input, const char* name, T* data, int n) {
    char rowname[2000];
    bool ok = !input.bad();

    // row format is 
    // name,1,2,3,4,5,6

    if (ok) {
      // read the name  first

      input.get(rowname, 2000, ',');
      // note: get will read a string upto the , character
      // it will leave the , character in the input buffer 

      // check that the caller is reading the correct row (name)
      // - if the user is reading the wrong row, return an error

      if (std::strcmp(rowname, name) != 0) {
        // wrong row
        std::cout << "Cannot parse row for " << name << std::endl;
        input.ignore(2000, '\n');
        ok = false;
      }
    }

    if (ok)
      // read the data array
      ok = read(input, data, n);

    // finish the line
    input.ignore(2000, '\n');
    return ok;
  }

  void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif