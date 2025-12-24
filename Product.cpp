#include "Product.h"

// Parametreli Constructor
Product::Product(long id, string name, double price) {
    this->id = id;
    this->name = name;
    this->price = price;
}

// Varsayýlan Constructor (Boþ ürün oluþturmak gerekirse diye)
Product::Product() {
    id = 0;
    name = "Bilinmiyor";
    price = 0.0;
}

// Destructor
Product::~Product() {
    // Þimdilik yapýlacak özel bir temizlik yok
}

// --- GETTER FONKSÝYONLARI ---
long Product::getID() const {
    return id;
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

// --- SETTER FONKSÝYONLARI ---
void Product::setID(long id) {
    this->id = id;
}

void Product::setName(const string& name) {
    this->name = name;
}

void Product::setPrice(double price) {
    if (price >= 0) {
        this->price = price;
    }
    else {
        cout << "Hata: Fiyat negatif olamaz!" << endl;
    }
}

// Özellikleri Yazdýr
void Product::printProperties() const {
    cout << "Urun ID: " << id
        << " | Isim: " << name
        << " | Fiyat: " << price << " TL" << endl;
}