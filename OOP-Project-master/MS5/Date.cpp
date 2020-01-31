//***********************************************************************
// OOP244 Milestone 5: The Product Hierarchy
// Filename:          Date.h
// Date:	            2018/07/11
// Author:	          Sharan Shanmugaratnam
//***********************************************************************

#include <iostream>
#include "Date.h"
using namespace std;

namespace AMA {

  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
  }

  void Date::errCode(int errorcode) {
    m_errorstate = errorcode;
  }

  // Default constructor.
  //
  Date::Date() {
    m_year = 0;
    m_month = 0;
    m_day = 0;
    m_comparator = 0;
    m_errorstate = 0;
  }

  //Constructor with 3 parameters.
  //
  Date::Date(int year, int month, int day) {
    int daysInMonth = mdays(month, year);
    if ((year >= min_year || year <= max_year) && (year > 0) && (daysInMonth != 13) && (day <= daysInMonth)) {
      m_year = year;
      m_month = month;
      m_day = day;
      m_comparator = year * 372 + month * 13 + day;
      m_errorstate = NO_ERROR;
    }
    else {
      m_year = 0;
      m_month = 0;
      m_day = 0;
      m_comparator = 0;
      m_errorstate = NO_ERROR;
    }
  }

  // Overloaded operators.
  //
  bool Date::operator==(const Date& rhs) const {
    return (m_comparator == rhs.m_comparator);
  }

  bool Date::operator!=(const Date& rhs) const {
    return (m_comparator != rhs.m_comparator);
  }

  bool Date::operator<(const Date& rhs) const {
    return (m_comparator < rhs.m_comparator);
  }

  bool Date::operator>(const Date& rhs) const {
    return (m_comparator > rhs.m_comparator);
  }

  bool Date::operator<=(const Date& rhs) const {
    return (m_comparator <= rhs.m_comparator);
  }

  bool Date::operator>=(const Date& rhs) const {
    return (m_comparator >= rhs.m_comparator);
  }

  // Error state functions.
  //
  int Date::errCode() const {
    return m_errorstate;
  }

  bool Date::bad() const {
    return m_errorstate != 0;
  }

  // Reading a date from user input.
  //
  std::istream& Date::read(std::istream& istr) {
    char seperator;

    istr.clear();
    istr >> m_year >> seperator >> m_month >> seperator >> m_day;

    if (istr.fail()) {
      m_year = 0;
      m_month = 0;
      m_day = 0;
      m_comparator = 0;
      m_errorstate = CIN_FAILED;
    }
    else if ((m_year < min_year) || (m_year > max_year)) {
      m_year = 0;
      m_month = 0;
      m_day = 0;
      m_comparator = 0;
      m_errorstate = YEAR_ERROR;
    }
    else if ((m_month < 1) || (m_month > 12)) {
      m_year = 0;
      m_month = 0;
      m_day = 0;
      m_comparator = 0;
      m_errorstate = MON_ERROR;
    }
    else if (m_day > mdays(m_month, m_year)) {
      m_year = 0;
      m_month = 0;
      m_day = 0;
      m_comparator = 0;
      m_errorstate = DAY_ERROR;
    }

    return istr;
  }

  // Prints a date.
  //
  std::ostream& Date::write(std::ostream& ostr) const {
    ostr.fill('0');
    ostr << m_year << "/";
    ostr.width(2);
    ostr << m_month << "/";
    ostr.width(2);
    ostr << m_day;

    return ostr;
  }

  std::ostream& operator<<(std::ostream& ostr, const Date& writeDate){
    writeDate.write(ostr);
    return ostr;
  }
  std::istream& operator>>(std::istream& istr, Date& readDate){
    readDate.read(istr);
    return istr;
  }

}
