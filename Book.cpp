// Book.cpp
// Ayşe Ceylin Erol
// 152120231085
// 27.11.2025
// Açıklama: Book sınıfındaki metotların uygulamaları

#include "Book.h"
#include <iostream> 

using namespace std;

// Constructor, Üst sınıf Product'ı ve alt sınıfın özelliklerini başlatır
Book::Book(int id, const string& name, double price,
    const string& author, const string& publisher, const int page)
    : Product(id, name, price), author(author), publisher(publisher), page(page) {
}

//Getters
string Book::getAuthor() const { return author; }
string Book::getPublisher() const { return publisher; }
int Book::getPage() const { return page; }

//Setters
void Book::setAuthor(const string& author) { this->author = author; }
void Book::setPublisher(const string& publisher) { this->publisher = publisher; }
void Book::setPage(int page) { this->page = page; }

// printProperties() metodu Product'tan miras alınan metodu özelleştirir
void Book::printProperties() const {
    cout << "=== BOOK ===" << endl;

    Product::printProperties();
    cout << "Author: " << author << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Pages: " << page << endl;
}

//Destructor
Book::~Book() {}