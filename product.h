#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
using namespace std;

class Product {
protected :
	int id;
	double price;
	string name;
public:
	Product (int id = 0, double price = 0.0, string name = "");
	
	virtual void printProperties() const = 0;
	
};
#endif