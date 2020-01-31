//***********************************************************************
// OOP244 Milestone 5: The Product Hierarchy
// Filename:           Product.cpp
// Date:	             2018/07/28
// Author:	           Sharan Shanmugaratnam
//***********************************************************************

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Product.h"
#include "ErrorState.h"

using namespace std;

namespace AMA {

  void Product::name(const char* name) {
    if (name == nullptr) {
      m_name = nullptr;
    }
    else {
      m_name = new char[max_name_length + 1];
      strncpy(m_name, name, max_name_length + 1);
      m_name[max_name_length] = '\0';
    }
  }

  const char* Product::name() const {
    return m_name;
  }

  const char* Product::sku() const {
    return m_sku;
  }

  const char* Product::unit() const {
    return m_unit;
  }

  bool Product::taxed() const {
    return m_taxable;
  }

  double Product::price() const {
    return m_pricePreTax;
  }

  double Product::cost() const {
    if (m_taxable) {
      return m_pricePreTax + (m_pricePreTax*tax_rate);
    }
    else {
      return m_pricePreTax;
    }
  }

  void Product::message(const char* errState) {
    m_errState.message(errState);
  }

  bool Product::isClear() const {
    return (m_errState.message() == NULL);
  }

  // Constructor with one argument.
  //
  Product::Product(char type) {
    m_productType = type;
    m_sku[0] = '\0';
    m_unit[0] = '\0';
    m_name = nullptr;
    m_qtyOnHand = 0;
    m_qtyNeeded = 0;
    m_pricePreTax = 0.0;
    m_taxable = false;
  }

  // Constructor with seven arguments.
  //
  Product::Product(const char* sku, const char* name_, const char* unit, int qtyOnHand, bool taxable, double pricePreTax, int qtyNeeded) {
    strcpy(m_sku, sku);
    name(name_);
    strcpy(m_unit, unit);
    m_qtyOnHand = qtyOnHand;
    m_taxable = taxable;
    m_pricePreTax = pricePreTax;
    m_qtyNeeded = qtyNeeded;
  }

  // Copy constructor.
  //
  Product::Product(const Product& product) {
    if (product.m_name != '\0') {
      name(product.m_name);
    }

    strcpy(m_sku, product.m_sku);
    strcpy(m_unit, product.m_unit);
    strncpy(m_name, product.m_name, max_name_length + 1);

    m_qtyOnHand = product.m_qtyOnHand;
    m_taxable = product.m_taxable;
    m_pricePreTax = product.m_pricePreTax;
    m_qtyNeeded = product.m_qtyNeeded;
  }

  // Copy Assignment Operator.
  //
  Product& Product::operator= (const Product& product) {
    if (this != &product) { // Check for self-assignment.
      strcpy(m_sku, product.m_sku);
      strcpy(m_unit, product.m_unit);

      m_qtyOnHand = product.m_qtyOnHand;
      m_taxable = product.m_taxable;
      m_pricePreTax = product.m_pricePreTax;
      m_qtyNeeded = product.m_qtyNeeded;

      delete[] m_name;
      name(product.m_name);
    }

    return *this;
  }

  // Destructor.
  //
  Product::~Product() {
    delete[] m_name;
  }

  std::fstream& Product::store(std::fstream& file, bool newLine) const {
    file << m_productType << "," << m_sku << "," << m_name << "," << m_unit << "," << m_taxable << "," << m_pricePreTax
      << "," << m_qtyOnHand << "," << m_qtyNeeded;

    if (newLine) {
      file << endl;
    }

    return file;
  }

  std::fstream& Product::load(std::fstream& file) {
    char f_sku[max_sku_length + 1];
    char* f_name = new char[max_name_length + 1];
    char f_unit[max_unit_length + 1];
    int f_qtyOnHand;
    int f_qtyNeeded;
    double f_pricePreTax;
    char f_taxed;
    bool f_taxable;
    Product load;

    if (file.is_open()) {
      file.get(f_sku, max_sku_length, ',');
      file.ignore();

      file.get(f_name, max_name_length, ',');
      file.ignore();
      
      file.get(f_unit, max_unit_length, ',');
      file.ignore();
      
      file >> f_taxed;
      file.ignore();
      
      file >> f_pricePreTax;
      file.ignore();
      
      file >> f_qtyOnHand;
      file.ignore();
      
      file >> f_qtyNeeded;
      file.ignore();
      
      if (f_taxed == '0') {
        f_taxable = false;
      }
      else {
        f_taxable = true;
      }

      load = Product(f_sku, f_name, f_unit, f_qtyOnHand, f_taxable, f_pricePreTax, f_qtyNeeded);

      *this = load;
    }

    //delete[] load.m_name;
    //load.m_name = nullptr;

    return file;
  }

  std::ostream& Product::write(std::ostream& os, bool linear) const {
    if (m_errState.message() != nullptr) {
      os << m_errState;
    }
    else if (linear) {
      os << setw(max_sku_length) << left << m_sku << "|" << setw(20) << left << m_name << "|"
        << setw(7) << right << fixed << setprecision(2) << cost() << "|"
        << setw(4) << right << m_qtyOnHand << "|" << setw(10) << left << m_unit << "|"
        << setw(4) << right << m_qtyNeeded << "|";
    }
    else {
      os << " Sku: " << m_sku << endl;
      os << " Name (no spaces): " << m_name << endl;
      os << " Price: " << m_pricePreTax << endl;
      if (m_taxable) {
        os << " Price after tax: " << cost() << endl;
      }
      else {
        os << " Price after tax: " << "N/A" << endl;
      }
      os << " Quantity on Hand: " << m_qtyOnHand << " " << m_unit << endl;
      os << " Quantity needed: " << m_qtyNeeded;
    }

    return os;
  }

  std::istream& Product::read(std::istream& is) {
    char f_sku[max_sku_length + 1];
    char* f_name = new char[max_name_length + 1];
    char f_unit[max_unit_length + 1];
    int f_qtyOnHand;
    int f_qtyNeeded;
    double f_pricePreTax;
    char f_taxed;
    bool f_taxable;
    bool valid = true; // Flag.

    cout << " Sku: ";
    is >> f_sku;
    cout << " Name (no spaces): ";
    is >> f_name;
    cout << " Unit: ";
    is >> f_unit;


    while (valid) {
      cout << " Taxed? (y/n): ";
      is >> f_taxed;
      if (f_taxed == 'y' || f_taxed == 'Y' || f_taxed == 'n' || f_taxed == 'N') {
        if (f_taxed == 'n' || f_taxed == 'N') {
          f_taxable = false;
        }
        else {
          f_taxable = true;
        }
        break;
      }
      else {
        valid = false;
        is.setstate(std::ios::failbit);
        message("Only (Y)es or (N)o are acceptable");
        break;
      }
    }

    while (valid) {
      cout << " Price: ";
      is >> f_pricePreTax;
      if (is.fail()) {
        is.setstate(std::ios::failbit);
        message("Invalid Price Entry");
        valid = false;
        break;
      }
      else {
        valid = true;
        break;
      }
    }

    while (valid) {
      cout << " Quantity on hand: ";
      is >> f_qtyOnHand;
      if (is.fail()) {
        is.setstate(std::ios::failbit);
        message("Invalid Quantity Entry");
        valid = false;
        break;
      }
      else {
        valid = true;
        break;
      }
    }

    while (valid) {
      cout << " Quantity needed: ";
      is >> f_qtyNeeded;
      is.ignore(); // Needed for submitter.
      if (is.fail()) {
        is.setstate(std::ios::failbit);
        message("Invalid Quantity Needed Entry");
        valid = false;
        break;
      }
      else {
        valid = true;
        break;
      }
    }

    if (valid) {
      *this = Product(f_sku, f_name, f_unit, f_qtyOnHand, f_taxable, f_pricePreTax, f_qtyNeeded);
      m_errState.clear();
    }

    return is;
  }

  bool Product::operator== (const char* sku) const {
    return (strcmp(sku, m_sku) == 0);
  }

  double Product::total_cost() const {
    double cost;
    if (m_taxable) {
      cost = m_qtyOnHand * m_pricePreTax * (1 + tax_rate);
    }
    else {
      cost = m_qtyOnHand * m_pricePreTax;
    }

    return cost;
  }

  void Product::quantity(int qtyOnHand) {
    m_qtyOnHand = qtyOnHand;
  }

  bool Product::isEmpty() const {
    return (m_name[0] == '\0');
  }

  int Product::qtyNeeded() const {
    return m_qtyNeeded;
  }

  int Product::quantity() const {
    return m_qtyOnHand;
  }

  bool Product::operator>(const char* sku) const {
    return (strcmp(m_sku, sku) > 0);
  }

  bool Product::operator>(const iProduct& iproduct) const {
    return (strcmp(m_name, iproduct.name()) > 0);
  }

  int Product::operator+=(int quantityAdded) {
    if (quantityAdded > 0) {
      m_qtyOnHand += quantityAdded;
      return m_qtyOnHand;
    }
    else {
      return m_qtyOnHand;
    }
  }

  std::ostream& operator<< (std::ostream& os, const iProduct& iproduct) {
    iproduct.write(os, true);
    return os;
  }

  std::istream& operator>> (std::istream& is, iProduct& iproduct) {
    iproduct.read(is);
    return is;
  }

  double operator+= (double& cost, const iProduct& iproduct) {
    cost += iproduct.total_cost();
    return cost;
  }
}