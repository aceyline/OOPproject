#ifndef BOOKSTORE_APP_H
#define BOOKSTORE_APP_H

#include <vector>
#include <memory> // unique_ptr için
// Diğer sınıf başlık dosyalarını buraya dahil edin (Customer.h, Product.h, vb.)
// Örneğin:
// #include "Customer.h"
// #include "Product.h"
// #include "Book.h"
// ...

class BookstoreApp {
private:
    std::vector<std::unique_ptr<Customer>> customers;
    std::vector<std::unique_ptr<Product>> products; 
    // ... Diğer veriler ve yardımcı fonksiyonlar

public:
    BookstoreApp();
    void run(); // Uygulamayı başlatan ana döngü
    void setupInitialData(); // Başlangıçtaki 5 müşteri ve 9 ürünü ekler [cite: 109]
    
    // Menü İşlevleri
    void showMainMenu();
    void showCustomerMenu();
    void showItemMenu(); // Ürün (Item) ekleme/listeleme
    void showShoppingMenu();
    
    // Müşteri İşlevleri
    void addNewCustomer();
    void listCustomers();

    // Alışveriş İşlevleri
    void handleLogin();
    // ... Diğer alışveriş menüsü işlevleri
};

#endif // BOOKSTORE_APP_H