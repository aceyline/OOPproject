/*
	Ýkra Selenay Yýlmaz - 152120231102
	20 / 11 / 2025
*/

#ifndef CASH_H
#define CASH_H

#include "Payment.h"

class Cash : public Payment{
public:
	Cash(double amount = 0.0);
	void performPayment();
};
#endif

