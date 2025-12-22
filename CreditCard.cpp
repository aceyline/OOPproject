// CreditCard.cpp
// 152120211125 RÜMEYSA CELİK 

#include "CreditCard.h"

CreditCard::CreditCard(double amount, long number, string type, string expDate)
    : Payment(amount) {
    this->number = number;
    this->type = type;
    this->expDate = expDate;
}

long CreditCard::getNumber() const { return number; }
void CreditCard::setNumber(long number) { this->number = number; }

string CreditCard::getType() const { return type; }
void CreditCard::setType(string type) { this->type = type; }

string CreditCard::getExpDate() const { return expDate; }
void CreditCard::setExpDate(string expDate) { this->expDate = expDate; }

void CreditCard::performPayment() {
}
