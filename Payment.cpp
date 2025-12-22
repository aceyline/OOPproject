// Payment.cpp
// 152120211125 RÜMEYSA CELİK

#include "Payment.h"

Payment::Payment(double amount) {
    this->amount = amount;
}

Payment::~Payment() {
}

double Payment::getAmount() const {
    return amount;
}

void Payment::setAmount(double amount) {
    this->amount = amount;
}
