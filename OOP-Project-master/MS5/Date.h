//***********************************************************************
// OOP244 Milestone 1: The Date Class
// Filename:          Date.h
// Date:	            2018/07/11
// Author:	          Sharan Shanmugaratnam
//***********************************************************************

#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace AMA {

  const int min_year = 2000;
  const int max_year = 2030;

  const int NO_ERROR = 0;
  const int CIN_FAILED = 1;
  const int YEAR_ERROR = 2;
  const int MON_ERROR = 3;
  const int DAY_ERROR = 4;

  class Date {
    // Private members
    //
    int m_year;
    int m_month;
    int m_day;
    int m_comparator;
    int m_errorstate;
    int mdays(int, int)const;
    void errCode(int errorCode);

  public:
    // Public members
    //
    Date();
    Date(int year, int month, int day);

    bool operator==(const Date& rhs) const;
    bool operator!=(const Date& rhs) const;
    bool operator<(const Date& rhs) const;
    bool operator>(const Date& rhs) const;
    bool operator<=(const Date& rhs) const;
    bool operator>=(const Date& rhs) const;

    int errCode() const;
    bool bad() const;
    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr) const;

  };

  std::ostream& operator<<(std::ostream& ostr, const Date& writeDate);
  std::istream& operator>>(std::istream& istr, Date& readDate);
}

#endif