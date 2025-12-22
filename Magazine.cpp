// Magazine.cpp
// Ayşe Ceylin Erol
// 152120231085
// 27.11.2025
// Açıklama: Magazine sınıfındaki metotların uygulamalrı

#include "Magazine.h"


// Constructor, Üst sınıf Product'ı ve alt sınıfın özelliklerini başlatır
Magazine::Magazine(int id, const string& name, double price,
    int issue, const string& type)
    : Product(id, name, price), issue(issue), type(type) {
}

// Getters
int Magazine::getIssue() const { return issue; }
string Magazine::getType() const { return type; }

// Setters
void Magazine::setIssue(int issue) { this->issue = issue; }
void Magazine::setType(const string& type) { this->type = type; }

// printProperties() Metodu: Product'tan miras alınan metodu özelleştirir
void Magazine::printProperties() const {
    cout << "=== MAGAZINE ===" << endl;

    Product::printProperties();
    cout << "Issue: " << issue << endl;
    cout << "Type: " << type << endl;
}

//Destructor
Magazine::~Magazine() {}