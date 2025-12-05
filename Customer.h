<<<<<<< HEAD
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;

class Customer {
public:
    Customer(int id, double bonus, string name, string username, string password);
    void setId(int id);
    int getId() const;

    void setBonus(double bonus);
    double getBonus() const;

    void setName(const string& name);
    string getName() const;

    void setUsername(const string& username);
    string getUsername() const;

    void setPassword(const string& password);
    string getPassword() const;

    void addPurchase(double amount);
    void useBonus(double amount);

protected:
    int id;
    double bonus;
    string name;
    string username;
    string password;

}; 

#endif
=======
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    long customerID;
    std::string name;
    std::string address;
    std::string phone;
    double bonus;
    std::string email;
    std::string username;
    std::string password;

public:
    Customer(long id = 0, std::string n = "", std::string addr = "", std::string ph = "", std::string mail = "", std::string user = "", std::string pass = "");
    ~Customer();

    long getCustomerID() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhone() const;
    double getBonus() const;
    std::string getEmail() const;
    std::string getUsername() const;
    std::string getPassword() const;

    
    void setCustomeriD(long customerID);
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setPhone(const std::string& phone);
    void setBonus(double bonus);
    void setEmail(const std::string& email);
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);

    
    void sendBill();
    bool checkAccount(const std::string& username, const std::string& password);
    void addBonus(double bonus);
    void useBonus();
};

#endif 
>>>>>>> 714b09139d5f8633cb87fd5c5ca03e3f7dec6487
