<<<<<<< HEAD
﻿/*          Berfin SELVİ         -      152120241030 
        25.11.2025           Customer c++ dosyası   */
#include "customer.h"
=======
﻿#include "customer.h"
>>>>>>> ac6e212f065372984a87a8d900b2218b72453139
#include <iostream>
using namespace std;

Customer::Customer(int id, double bonus, string name, string username, string password)
    : id(id), bonus(bonus), name(name), username(username), password(password) {
}

void Customer::addPurchase(double amount) {
    double earnedBonus = amount * 0.01;
    bonus += earnedBonus;
    cout << "Alısveris: " << amount << " TL, Kazanılan Bonus: " << earnedBonus << " TL" << endl;
}

void Customer::useBonus(double amount) {
    if (amount <= bonus) {
        bonus -= amount;
        cout << "Kullanilan Bonus: " << amount << " TL" << endl;
    }
    else {
        cout << "Yetersiz bonus!" << endl;
    }
}


int Customer::getId() const {
    return id;
}

double Customer::getBonus() const {
    return bonus;
}

string Customer::getName() const {
    return name;
}

string Customer::getUsername() const {
    return username;
}

string Customer::getPassword() const {
    return password;
}


void Customer::setId(int id) {
    this->id = id;
}

void Customer::setBonus(double bonus) {
    this->bonus = bonus;
}

void Customer::setName(const string& name) {
    this->name = name;
}

void Customer::setUsername(const string& username) {
    this->username = username;
}

void Customer::setPassword(const string& password) {
    this->password = password;
}