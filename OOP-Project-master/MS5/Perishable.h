//***********************************************************************
// OOP244 Milestone 5: The Product Hierarchy
// Filename:           Perishable.h
// Date:	             2018/08/01
// Author:	           Sharan Shanmugaratnam
//***********************************************************************

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include <iostream>
#include "Product.h"
#include "Date.h"

namespace AMA {
  class Perishable : public Product {
    // Private Members
    //
    Date m_expiry;

    // Public Members
    //
  public:
    Perishable();
    std::fstream& store(std::fstream& file, bool newLine = true) const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear) const;
    std::istream& read(std::istream& is);
    const Date& expiry() const;
  };
}
#endif
