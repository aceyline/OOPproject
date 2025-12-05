// Yazan: [Birce Oğuz]
// Tarih: [25/11/2025]
#include "ShoppingCart.h"
#include <iostream>
#include <algorithm>

ShoppingCart::ShoppingCart(Customer* cust) 
    : paymentMethod(nullptr), customer(cust), isBonusUsed(false) {}

ShoppingCart::~ShoppingCart() {
    for (ProductToPurchase* p : productsToPurchase) {
        delete p;
    }
    productsToPurchase.clear();
}

double ShoppingCart::calculateTotalAmount() const {
    double total = 0.0;
    for (const auto& item : productsToPurchase) {
        if (item && item->getProduct()) {
            total += item->getProduct()->getPrice() * item->getQuantity();
        }
    }
    return total;
}

void ShoppingCart::setBonusUsed() {
    this->isBonusUsed = true;
}

void ShoppingCart::addProduct(Product* product, int quantity) {
    if (product == nullptr || quantity <= 0) {
        std::cout << "Gecersiz urun veya miktar." << std::endl;
        return;
    }
    ProductToPurchase* newPTP = new ProductToPurchase(product, quantity);
    productsToPurchase.push_back(newPTP);
    std::cout << product->getName() << " sepete eklendi. Miktar: " << quantity << std::endl;
}

void ShoppingCart::removeProduct(Product* product) {
    auto it = std::remove_if(productsToPurchase.begin(), productsToPurchase.end(), 
        [product](ProductToPurchase* ptp) {
            return ptp->getProduct() == product;
        });

    for (auto i = it; i != productsToPurchase.end(); ++i) {
        delete *i;
    }

    productsToPurchase.erase(it, productsToPurchase.end());

    std::cout << "Urun sepetten kaldirildi." << std::endl;
}

void ShoppingCart::printProducts() const {
    std::cout << "\n--- Sepetinizdeki Urunler ---" << std::endl;
    if (productsToPurchase.empty()) {
        std::cout << "Sepetiniz bos." << std::endl;
        return;
    }

    for (const auto& item : productsToPurchase) {
        std::cout << "Urun Adi: " << item->getProduct()->getName() 
                  << " | Miktar: " << item->getQuantity() 
                  << " | Birim Fiyat: " << item->getProduct()->getPrice() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

void ShoppingCart::placeOrder() {
    if (!customer || !paymentMethod) {
        std::cout << "Siparis icin musteri veya odeme yontemi eksik." << std::endl;
        return;
    }

    double totalAmount = calculateTotalAmount();
    double finalAmount = totalAmount;
    
    if (isBonusUsed && customer->getBonus() > 0.0) {
        double bonus = customer->getBonus();
        double usedBonus = (bonus > totalAmount) ? totalAmount : bonus;
        finalAmount -= usedBonus;
        customer->useBonus();
        std::cout << "Bonus kullanildi: " << usedBonus << " TL indirim uygulandi." << std::endl;
        isBonusUsed = false;
    }

    paymentMethod->setAmount(finalAmount);
    if (paymentMethod->performPayment()) {
        std::cout << "Odeme basarili. Tutar: " << finalAmount << " TL." << std::endl;
        
        double earnedBonus = totalAmount * 0.01;
        customer->addBonus(earnedBonus);
        std::cout << "Yeni bonus kazanildi: " << earnedBonus << " TL." << std::endl;

        customer->sendBill();
        
        for (ProductToPurchase* p : productsToPurchase) {
             delete p;
        }
        productsToPurchase.clear();
    } else {
        std::cout << "Odeme basarisiz. Siparis iptal edildi." << std::endl;
        cancelOrder();
    }
}

void ShoppingCart::cancelOrder() {
    std::cout << "Siparis iptal ediliyor. Sepet temizleniyor..." << std::endl;
    for (ProductToPurchase* p : productsToPurchase) {
        delete p;
    }
    productsToPurchase.clear();
}

void ShoppingCart::showInvoice() const {
    std::cout << "\n--- FATURA OZETI ---" << std::endl;
    std::cout << "Musteri: " << (customer ? customer->getName() : "Bilinmiyor") << std::endl;
    printProducts();
    std::cout << "Toplam Tutar (Bonus Oncesi): " << calculateTotalAmount() << " TL" << std::endl;
    std::cout << "----------------------" << std::endl;
}