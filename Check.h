/*
	Ýkra Selenay Yýlmaz - 152120231102
	20 / 11 / 2025
*/

#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "Payment.h"
using namespace std;

class Check : public Payment {
private:
	string name;
	string bankID;

public:
	Chech(double amount = 0.0,
		const string& name = "",
		const string& bankID = "");
	void performPayment();
	string getName() const;
	void setName(const string& name);
	string getBankID() const;
	void setBankID(const string& bankID);
};
#endif

