#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
private:
    long id;            // int yerine long
    string name;
    string address;     // Yeni eklendi
    string phone;       // Yeni eklendi
    double bonus;
    string email;       // Yeni eklendi
    string username;
    string password;

public:
    // Constructor güncellendi
    Customer(long id, string name, string address, string phone, double bonus, string email, string username, string password);

    void sendBill();
    void addPurchase(double amount); // addBonus mantýðý buranýn içinde olabilir
    void useBonus(double amount); // UML'de yok ama mantýklý
    bool checkAccount(string user, string pass); // Login kontrolü

    // Getters
    long getId() const;
    string getName() const;
    string getAddress() const;
    string getPhone() const;
    double getBonus() const;
    string getEmail() const;
    string getUsername() const;
    string getPassword() const;

    // Setters
    void setId(long id);
    void setName(const string& name);
    void setAddress(const string& address);
    void setPhone(const string& phone);
    void setBonus(double bonus);
    void setEmail(const string& email);
    void setUsername(const string& username);
    void setPassword(const string& password);
};

#endif