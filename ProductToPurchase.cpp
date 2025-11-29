// Yazan: [Birce Oğuz]
// Tarih: [25/11/2025]
#include "ProductToPurchase.h"
#include <iostream>

ProductToPurchase::ProductToPurchase(Product* p, int q) : product(p), quantity(q) {
    
}
ProductToPurchase::~ProductToPurchase() {
   
}

Product* ProductToPurchase::getProduct() const {
    
    return product;
}

int ProductToPurchase::getQuantity() const {
    
    return quantity;
}

void ProductToPurchase::setProduct(Product* product) {
    
    this->product = product;
}

void ProductToPurchase::setQuantity(int quantity) {
    
    this->quantity = (quantity > 0) ? quantity : 0;
}