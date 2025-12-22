// Magazine.h
// Ayşe Ceylin Erol
// 152120231085
// 27.11.2025
// Açıklama: Product sınıfından kalıtım alan Magazine sınıfının tanımı
//           Derginin Issue ve Type özelliklerini içerir

#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <iostream>
#include <string>

using namespace std; 

#include "Product.h" // Kalıtım alınan üst sınıf

class Magazine : public Product {
private:
  int issue;             
  string type;

public:
//Constructor
  Magazine(int id, const string& name, double price,
           int issue, const string& type); 

// Getters 
    int getIssue() const; 
    string getType() const;

// Setters
    void setIssue(int issue); 
    void setType(const string& type);

// printProperties metodu Product'tan miras alınır
    void printProperties() const override;

//Destructor
   ~Magazine();
};

#endif