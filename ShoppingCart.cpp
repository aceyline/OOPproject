#include "ShoppingCart.h"
#include <iostream>
#include <algorithm>

using namespace std;

ShoppingCart::ShoppingCart(Customer* cust)
    : paymentMethod(nullptr), customer(cust), isBonusUsed(false) {
}

ShoppingCart::~ShoppingCart() {
    for (auto item : productsToPurchase)
        delete item;
    productsToPurchase.clear();
}

void ShoppingCart::setPaymentMethod(Payment* payment) {
    paymentMethod = payment;
}

Payment* ShoppingCart::getPaymentMethod() const {
    return paymentMethod;
}

void ShoppingCart::addProduct(Product* product) {
    ProductToPurchase* newItem = new ProductToPurchase();

    newItem->setProduct(product);
    newItem->setQuantity(1); 

    productsToPurchase.push_back(newItem);

    cout << product->getName()
        << " sepete eklendi. (Fiyat: " << product->getPrice() << " TL)" << endl;
}

void ShoppingCart::removeProduct(Product* product) {
    auto it = productsToPurchase.begin();
    while (it != productsToPurchase.end()) {
        if ((*it)->getProduct()->getID() == product->getID()) {

            cout << (*it)->getProduct()->getName() << " sepetten cikarildi." << endl;

            delete* it; 
            it = productsToPurchase.erase(it); 
            return; 
        }
        else {
            ++it;
        }
    }
    cout << "Urun sepetinizde bulunamadi." << endl;
}

void ShoppingCart::printProducts() const {
    if (productsToPurchase.empty()) {
        cout << "Sepet bos." << endl;
        return;
    }

    cout << "=== SEPET ===" << endl;
    for (const auto& item : productsToPurchase) {
        cout << "Urun: " << item->getProduct()->getName()
            << " | Fiyat: " << item->getProduct()->getPrice()
            << " | Miktar: " << item->getQuantity() << endl;
    }
}

void ShoppingCart::showInvoice() const {
    double total = 0;

    cout << "=== FATURA ===" << endl;
    for (const auto& item : productsToPurchase) {
        double sub = item->getProduct()->getPrice() * item->getQuantity();
        cout << item->getProduct()->getName()
            << " x " << item->getQuantity()
            << " = " << sub << " TL" << endl;
        total += sub;
    }
    cout << "Toplam: " << total << " TL" << endl;
}

void ShoppingCart::placeOrder() {
    if (!paymentMethod || productsToPurchase.empty()) {
        cout << "Odeme yapilamadi!" << endl;
        return;
    }

    double total = 0;
    for (const auto& item : productsToPurchase)
        total += item->getProduct()->getPrice() * item->getQuantity();

    if (isBonusUsed && customer) {
        double used = min(customer->getBonus(), total);
        customer->useBonus(used);
        total -= used;
    }

    paymentMethod->setAmount(total);
    paymentMethod->performPayment();

    if (customer)
        customer->addPurchase(total);

    cout << "Siparis tamamlandi." << endl;
    productsToPurchase.clear();
}

void ShoppingCart::cancelOrder() {
    cout << "Siparis iptal edildi." << endl;
    productsToPurchase.clear();
}

void ShoppingCart::useBonus(bool use) {
    isBonusUsed = use;
}