// Product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    int ID;
    std::string name;
    double price;

public:
    
    virtual ~Product() {}

    virtual void printProperties() const = 0; 
    
    int getID() const { return ID; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }

    void setID(int id) { this->ID = id; }
    void setName(const std::string& n) { this->name = n; }
    void setPrice(double p) { this->price = p; }
};

#endif 