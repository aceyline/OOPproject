#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
protected:
    int id;
    string name;
    double price;
    

public:
    // Constructor - note the parameter order!
    Product(int id, string name, double price);

    // Virtual destructor for polymorphism
    virtual ~Product();

    // Getters
    int getID() const;
    double getPrice() const;
    string getName() const;

    // Setters
    void setID(int id);
    void setPrice(double price);
    void setName(const string& name);

    // Virtual function for polymorphism
    virtual void printProperties() const;
};

#endif