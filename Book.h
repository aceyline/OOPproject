// Book.h
// Ayşe Ceylin Erol
// 152120231085
// 27.11.2025
// Açıklama: Product sınıfından kalıtım alan Book sınıfının tanımı
//          Kitabın author, publisher ve page özelliklerini içerir

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std; 

#include "Product.h" // Kalıtım alınan temel sınıf

class Book : public Product {
private:
// Kitaba özgü private nitelikler
    string author;
    string publisher;
    int page;

public:
// Constructor, Product constructorı çağırır ve Book niteliklerini başlatır.
    Book(int id, const string& name, double price,
         const string& author, const string& publisher, int page);

//Getters
    string getAuthor() const;
    string getPublisher() const;
    int getPage() const;

// Setters
    void setAuthor(const string& author);
    void setPublisher(const string& publisher);
    void setPage(int page);

// printProperties metodu: Product'tan miras alınır ve özelleştirilir
    void printProperties() const override;

//Destructor
    ~Book();
};

#endif
