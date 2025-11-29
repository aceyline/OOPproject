// Payment.h
#ifndef PAYMENT_H
#define PAYMENT_H

class Payment {
protected:
    double amount; 

public:

    virtual ~Payment() {} 

    double getAmount() const;
    void setAmount(double amount);
    
    virtual bool performPayment() = 0; 
};

#endif 