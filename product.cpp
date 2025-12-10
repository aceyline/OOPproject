#include <string>
#include <iostream>
#include "product.h"
using namespace std;
Product::Product(int id, double price, string name) {
	this->id = id;
	this->price = price;
	this->name = name;
};
