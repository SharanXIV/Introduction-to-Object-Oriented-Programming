//***********************************************************************
// OOP244 Milestone 5: The Product Hierarchy
// Filename:           Product.h
// Date:	             2018/08/07
// Author:	           Sharan Shanmugaratnam
//***********************************************************************

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include <iostream>
#include <fstream>
#include "iProduct.h"
#include "ErrorState.h"

namespace AMA {
  const int max_sku_length = 7;
  const int max_unit_length = 10;
  const int max_name_length = 75;
  const double tax_rate = 0.13;

  class Product : public iProduct{
    // Private Members
    //
    char m_productType;
    char m_sku[max_sku_length + 1];
    char m_unit[max_unit_length + 1];
    char* m_name;
    int m_qtyOnHand;
    int m_qtyNeeded;
    double m_pricePreTax;
    bool m_taxable;

    // Protected Members
    //
  protected:
    ErrorState m_errState;
    void name(const char*);
    const char* name() const;
    const char* sku() const;
    const char* unit() const;
    bool taxed() const;
    double price() const;
    double cost() const;
    void message(const char*);
    bool isClear() const;

    // Public Members
    //
  public:
    Product(char type = 'N');
    Product(const char* sku, const char* name_, const char* unit, int qtyOnHand = 0, bool taxable = true, double pricePreTax = 0.0, int qtyNeeded = 0);
    Product(const Product& product);
    Product& operator= (const Product& product);
    ~Product();

    std::fstream& store(std::fstream& file, bool newLine = true) const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear) const;
    std::istream& read(std::istream& is);

    bool operator== (const char* sku) const;
    double total_cost() const;
    void quantity(int qtyOnHand);
    bool isEmpty() const;
    int qtyNeeded() const;
    int quantity() const;
    bool operator>(const char* sku) const;
    bool operator>(const iProduct& iproduct) const;
    int operator+=(int addUnit);
  };

  std::ostream& operator<< (std::ostream& os, const iProduct& iproduct);
  std::istream& operator>> (std::istream& is, iProduct& iproduct);
  double operator+= (double& cost, const iProduct& iproduct);
}
#endif