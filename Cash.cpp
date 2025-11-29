/*
	Ýkra Selenay Yýlmaz - 152120231102
	20 / 11 / 2025
*/

#include "Cash.h"
#include <iostream>
using namespace std;

Cash::Cash(double amount) : Payment(amount) {}
void Cash::performPayment() {
	cout << "Cash payment of " << amount << "is completed.\n";	
}
