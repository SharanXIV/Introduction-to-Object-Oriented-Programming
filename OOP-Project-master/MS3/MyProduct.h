//***********************************************************************
// OOP244 Milestone 3: The Product Class
// Filename:           MyProduct.h
// Date:	             2018/07/28
// Author:	           Sharan Shanmugaratnam
//***********************************************************************

#ifndef AMA_MY_PRODUCT_H
#define AMA_MY_PRODUCT_H
#include <fstream>
#include "Product.h"

namespace AMA {
	class MyProduct : public Product {
    // Public Members
    //
	public:
		MyProduct();
		MyProduct(const char* sku, const char* name, const char* unit, int qty = 0,
			bool isTaxed = true, double price = 0.0, int qtyNeeded = 0);
		const char* sku() const;
		const char* name() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
	};

	class Test {
		MyProduct product;
		const char* filename;
    // Public Members
    //
	public:
		Test(const char* file);
		Test(const char* file, const char* theSku, const char* theName);
		std::fstream& store(std::fstream& file, bool addNewLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		int operator+=(int value);
		bool operator==(const char* sku) const;
		friend std::ostream& operator<<(std::ostream& os, const Test& test);
		friend double operator+=(double& d, const Test& test);
		friend std::istream& operator>>(std::istream& is, Test& test);
	};
}
#endif
