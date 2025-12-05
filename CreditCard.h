// CreditCard.h
// 152120211125 RÜMEYSA CELİK

#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "Payment.h"
#include <string>

using namespace std;

class CreditCard : public Payment {
private:
    long number;      
    string type;     
    string expDate;   

public:
    CreditCard(double amount, long number, string type, string expDate);

   
    long getNumber() const;
    void setNumber(long number);

    string getType() const;
    void setType(string type);

    string getExpDate() const;
    void setExpDate(string expDate);

    void performPayment() override; 
};

#endif
