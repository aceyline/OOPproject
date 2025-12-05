// Yazan: [Birce Oğuz]
// Tarih: [25/11/2025]
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "ProductToPurchase.h"
#include "Customer.h"  
#include "Payment.h"   

class ShoppingCart {
private:
    
    std::vector<ProductToPurchase*> productsToPurchase;
    Payment* paymentMethod;
    Customer* customer;
    bool isBonusUsed;

public:
    
    ShoppingCart(Customer* cust = nullptr);
    ~ShoppingCart();

    Payment* getPaymentMethod() const;
    Customer* getCustomer() const;
    bool getIsBonusUsed() const;

    void setPaymentMethod(Payment* paymentMethod);
    void setCustomer(Customer* customer);
    void setBonusUsed(); 
    void addProduct(Product* product, int quantity); 
    void removeProduct(Product* product);
    void printProducts() const;
    void placeOrder();
    void cancelOrder();
    void showInvoice() const;

private:
    
    double calculateTotalAmount() const;
};

#endif 