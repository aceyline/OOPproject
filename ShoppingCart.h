#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "ProductToPurchase.h"
#include "Payment.h"
#include "Customer.h"
#include "Product.h"

class ShoppingCart {
private:
    std::vector<ProductToPurchase*> productsToPurchase;
    Payment* paymentMethod;
    Customer* customer;
    bool isBonusUsed;

public:
    ShoppingCart(Customer* cust = nullptr);
    ~ShoppingCart();

    void setPaymentMethod(Payment* payment);
    Payment* getPaymentMethod() const;

    void addProduct(Product* product);
    void removeProduct(Product* product);

    void printProducts() const;
    void showInvoice() const;

    void placeOrder();
    void cancelOrder();

    void useBonus(bool use);
};

#endif