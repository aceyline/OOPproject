#include <string>
#include <iostream>
#include "Product.h"

using namespace std;

// Constructor - Fixed parameter type
Product::Product(int id, string name,double price) {
    this->id = id;
    this->name = name;
    this->price = price;    
}

// Getters
int Product::getID() const {
    return id;
}

double Product::getPrice() const {
    return price;
}

string Product::getName() const {
    return name;
}

// Setters
void Product::setID(int id) {
    this->id = id;
}

void Product::setPrice(double price) {
    this->price = price;
}

void Product::setName(const string& name) {
    this->name = name;
}

// Print properties
void Product::printProperties() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << " TL" << endl;
}

// Destructor
Product::~Product() {
}