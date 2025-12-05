// Yazan: [Birce Oğuz]
// Tarih: [25/11/2025]
#ifndef PRODUCTTOPURCHASE_H
#define PRODUCTTOPURCHASE_H
#include "Product.h" 
class ProductToPurchase {
private:
    Product* product; 
    int quantity;     

public:
    
    ProductToPurchase(Product* p = nullptr, int q = 0);
    ~ProductToPurchase(); 

    Product* getProduct() const;
    int getQuantity() const;

    void setProduct(Product* product);
    void setQuantity(int quantity);
};

#endif 