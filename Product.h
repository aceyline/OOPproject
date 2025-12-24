#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

using namespace std;

class Product {
protected:
    long id;            // UML'de int olabilir ama ID genelde long tutulur
    string name;
    double price;

public:
    // Constructor (Kurucu)
    Product(long id, string name, double price);

    // Varsayýlan Constructor (Bazen gereklidir)
    Product();

    // Destructor (Sanal olmasý ileride Book, Magazine eklerken önemli)
    virtual ~Product();

    // Getter Fonksiyonlarý (Verileri okumak için)
    long getID() const;
    string getName() const;
    double getPrice() const;

    // Setter Fonksiyonlarý (Verileri deðiþtirmek için - Ýsteðe baðlý)
    void setID(long id);
    void setName(const string& name);
    void setPrice(double price);

    // Ürün özelliklerini yazdýrma (Sanal fonksiyon)
    virtual void printProperties() const;
};

#endif