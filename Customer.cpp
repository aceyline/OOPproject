#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(long id, string name, string address, string phone, double bonus, string email, string username, string password)
    : id(id), name(name), address(address), phone(phone), bonus(bonus), email(email), username(username), password(password) {
}

// UML'deki sendBill metodu
void Customer::sendBill() {
    cout << "Fatura " << email << " adresine ve " << address << " konumuna gonderildi." << endl;
}

// Alışveriş yapma ve bonus kazanma
void Customer::addPurchase(double amount) {
    double earnedBonus = amount * 0.01; // %1 Bonus kuralı
    bonus += earnedBonus;
    cout << "Alisveris: " << amount << " TL, Kazanilan Bonus: " << earnedBonus << " TL" << endl;
}

// Bonus kullanma
void Customer::useBonus(double amount) {
    if (amount <= bonus) {
        bonus -= amount;
        cout << "Kullanilan Bonus: " << amount << " TL" << endl;
    }
    else {
        cout << "Yetersiz bonus! Mevcut bonusunuz: " << bonus << endl;
    }
}

// Kullanıcı adı ve şifre doğrulama (Login işlemi için)
bool Customer::checkAccount(string user, string pass) {
    if (this->username == user && this->password == pass) {
        return true;
    }
    return false;
}

// --- Getter Fonksiyonları ---
long Customer::getId() const { return id; }
string Customer::getName() const { return name; }
string Customer::getAddress() const { return address; }
string Customer::getPhone() const { return phone; }
double Customer::getBonus() const { return bonus; }
string Customer::getEmail() const { return email; }
string Customer::getUsername() const { return username; }
string Customer::getPassword() const { return password; }

// --- Setter Fonksiyonları ---
void Customer::setId(long id) { this->id = id; }
void Customer::setName(const string& name) { this->name = name; }
void Customer::setAddress(const string& address) { this->address = address; }
void Customer::setPhone(const string& phone) { this->phone = phone; }
void Customer::setBonus(double bonus) { this->bonus = bonus; }
void Customer::setEmail(const string& email) { this->email = email; }
void Customer::setUsername(const string& username) { this->username = username; }
void Customer::setPassword(const string& password) { this->password = password; }