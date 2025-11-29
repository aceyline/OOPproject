/*
	İkra Selenay Yılmaz - 152120231102
	20 / 11 / 2025
*/

#include "Check.h"
#include <iostream>
using namespace std;

Check::Check(double amount,
			const string& name,
			const string& bankID)
    : Payment(amount), name(name), bankID(bankID) {
}

void Check::performPayment() {
	cout << "Cash payment of " << amount << "is completed.\n";
	cout << "Name = " << name << endl;
	cout << "Bank id = " << bankID << endl;
}

string Check::getName() const { return name; }

void Check::setName(const string& name) { this->name = name; }
	
string Check::getBankID() const { return bankID; }

void Check::setBankID(const string& bankID) { this->bankID = bankID; }
	
