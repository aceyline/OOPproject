#include <iostream>
#include <vector>
#include <string>
#include "Customer.h"
#include "Product.h"
#include "ShoppingCart.h"

using namespace std;

class Menu {
private:
    string title;
    vector<string> options;

public:
    Menu(string menuTitle) {
        title = menuTitle;
    }

    void addOption(string optionText) {
        options.push_back(optionText);
    }

    void show() const {
        cout << "\n--- " << title << " ---" << endl;
        for (size_t i = 0; i < options.size(); i++) {
            cout << (i + 1) << ". " << options[i] << endl;
        }
        cout << "Secim: ";
    }

    int getChoice() const {
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            return -1;
        }
        return choice;
    }
};


void customerMenuLoop(vector<Customer>& customers) {
    Menu custMenu("Musteri Menusu");
    custMenu.addOption("Sisteme yeni bir musteri ekleyiniz");
    custMenu.addOption("Sistemdeki musterileri gosteriniz");
    custMenu.addOption("Geri");

    int choice;
    do {
        custMenu.show();
        choice = custMenu.getChoice();

        switch (choice) {
        case 1:
        {
                cout << "\nYeni musteri ekleme fonksiyonu cagirildi\n";
                long id;
                string name;
                string address;
                string phone;
                double bonus = 0;
                string email;
                string username;
                string password;

                cin.ignore();

                cout << "Isim (Name): "; getline(cin, name);
                cout << "Adres (Address): "; getline(cin, address);
                cout << "Telefon (Phone): "; getline(cin, phone);
                cout << "Email: "; getline(cin, email);
                cout << "Kullanici Adi: "; cin >> username;
                cout << "Sifre: "; cin >> password;
                cout << "ID Giriniz: "; cin >> id;

                id = customers.size() + 1;
                Customer yeniMusteri(id, name, address, phone,
                    bonus, email, username, password);
                customers.push_back(yeniMusteri);
                cout << "\nMusteri kaydedildi! ID: " << id << "\n";
        }
        break;

        case 2:
        {
            cout << "\nKayitli musteriler getiriliyor...\n";
            if (customers.empty()) {
                cout << "Hic musteri kaydi bulunamadi.\n";
            }
            else {
                for (const auto& cust : customers) {
                    cout << "ID: " << cust.getId()
                        << " | Isim: " << cust.getName()
                        << " | Email: " << cust.getEmail() << endl;
                }
            }
        }
        break;

        case 3:
            cout << "Ana menuye donuluyor...\n";
            break;

        default:
            cout << "Gecersiz secim!\n";
        }
    } while (choice != 3);
}


void itemMenuLoop(vector<Product>& products) {
    Menu itemMenu("Urun Menu");
    itemMenu.addOption("Yeni urun ekle");
    itemMenu.addOption("Urunleri listele");
    itemMenu.addOption("Geri");

    int choice;
    do {
        itemMenu.show();
        choice = itemMenu.getChoice();

        switch (choice) {
        case 1:
        {
            cout << "\nUrun ekleme...\n";
            int id_p;
            string name_p;
            double price;
            cin.ignore();
            id_p = products.size() + 1;
            cout << "Isim:"; getline(cin, name_p);
            //cout << "ID: "; cin >> id_p;  //Eklemeyedebiliriz.otomatik direkt          
            cout << "Fiyat:"; cin >> price;

            Product newProduct(id_p, name_p, price);
            products.push_back(newProduct);

            cout << "\nUrun sisteme kaydedildi! ID:" << id_p << "\n";
            break;
        }
            
        
        case 2:
        {
            cout << "\nUrun listeleme...\n";
            if (products.empty()) { cout << "Urun kaydi bulunamadý.\n"; }
            else {
                for (const auto& prod : products) {
                    cout << "ID: " << prod.getID()
                        << "| Isim: " << prod.getName()
                        << "| Fiyat: \n" << prod.getPrice() << endl;
                }
            }
            break;
        }
        case 3:
        {
            break;
        }
        default:
            cout << "Gecersiz secim!\n";
        }
    } while (choice != 3);
}

void shoppingMenuLoop(vector<Customer>& customers, vector<Product>& products) {
    Menu shopMenu("Shopping Menu");
    shopMenu.addOption("Login");
    shopMenu.addOption("Add Product");
    shopMenu.addOption("Remove Product");
    shopMenu.addOption("List All Products");
    shopMenu.addOption("List Shopping Cart");
    shopMenu.addOption("Show Bonus");
    shopMenu.addOption("Use Bonus");
    shopMenu.addOption("Place Order");
    shopMenu.addOption("Cancel Order");
    shopMenu.addOption("Show Invoice");
    shopMenu.addOption("Quit (Back)");

    int choice;
    Customer* currentCustomer = nullptr;
    ShoppingCart myCart;

    do {
        if (currentCustomer != nullptr) {
            cout << "\nCevrimici Kullanici: " <<
                currentCustomer->getName() << "\n";
        }
        else {
            cout << "\nYanlis Kullanici!\n";
        }

        shopMenu.show();
        choice = shopMenu.getChoice();

        switch (choice) {
        case 1:
        {
            cout << "Kullanici girisi yapiliyor\n";
            string username, password;
            cin.ignore();

            cout << "Kullanici Adi: "; cin >> username;
            cout << "Sifre: "; cin >> password;

            bool found = false;
            for (auto& cust : customers) {
                if (cust.getUsername() == username && cust.getPassword() == password) {
                    currentCustomer = &cust;
                    cout << "Giris Basarili! Hosgeldin " << cust.getName() << ".\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Hatali kullanici adi veya sifre!\n";
            }
            break;
        }

        case 2:
        {
            if (currentCustomer == nullptr) {
                cout << "Lutfen once giris yapin! (Secenek 1)\n";
                break;
            }

            cout << "\nUrun listeleniyor...\n";
            for (const auto& p : products) {
                cout << "ID: " << p.getID() << " - " << p.getName()
                    << " (" << p.getPrice() << " TL)\n";
            }

            cout << "\nSepete eklemek istediginiz Urun ID'sini girin: ";
            int targetId;
            cin >> targetId;

            bool productFound = false;
            for (auto& p : products) {
                if (p.getID() == targetId) {
                    myCart.addProduct(&p);
                    cout << p.getName() << " sepete eklendi.\n";
                    productFound = true;
                    break;
                }
            }
            if (!productFound) cout << "Gecersiz Urun ID!\n";

            break;
        }

        case 3:
        {
            if (currentCustomer == nullptr) {
                cout << "Lutfen once giris yapin.\n";
                break;
            }
            cout << "Silmek istediginiz Urun ID: ";
            int pid;
            cin >> pid;

            bool found = false;
            for (auto& p : products) {
                if (p.getID() == pid) {
                    myCart.removeProduct(&p);
                    cout << "Islem tamamlandi.\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Gecersiz ID.\n";
            break;
        }

        case 4:
        {
            cout << "\nTUM URUNLER\n";
            for (const auto& p : products) {
                cout << "ID: " << p.getID() << " | " << p.getName()
                    << " | " << p.getPrice() << " TL\n";
            }
            break;
        }

        case 5:
        {
            if (currentCustomer == nullptr) {
                cout << "Lutfen once giris yapin.\n";
            }
            else {
                cout << "\n--- SEPETINIZ ---\n";
                myCart.printProducts(); 
            }
            break;
        }

        case 6: 
        {
            if (currentCustomer == nullptr) cout << "Giris yapmalisiniz.\n";
            else {
                cout << "Mevcut Bonusunuz: " << currentCustomer->getBonus() << " TL\n";
            }
            break;
        }

        case 7: 
        {
            if (currentCustomer == nullptr) {
                cout << "Giris yapmalisiniz.\n";
                break;
            }
            else {
                myCart.useBonus(true);
                cout << "Bonuslariniz siparis tutarindan dusulecektir.\n";
            }
            break;
        }

        case 8: 
        {
            if (currentCustomer == nullptr) {
                cout << "Giris yapmalisiniz.\n";
            }
            else {
                cout << "Siparis isleme aliniyor...\n";
                myCart.placeOrder();
            }
            break;
        }

        case 9: 
        {
            if (currentCustomer == nullptr) {
                cout << "Giris yapmalisiniz.\n";
            }
            else {
                myCart.cancelOrder(); 
                cout << "Sepetiniz bosaltildi.\n";
            }
            break;
        }

        case 10: 
        {
            if (currentCustomer == nullptr) {
                cout << "Giris yapmalisiniz.\n";
            }
            else {
                myCart.showInvoice(); 
            }
            break;
        }

        case 11:
        {
            cout << "Ana menuye donuluyor...\n";
            break;
        }
        default:
            cout << "Gecersiz secim!\n";
        }
    } while (choice != 11);     
}


int main() {
    Menu mainMenu("Ana Menu");
    mainMenu.addOption("Musteri");
    mainMenu.addOption("Urun");
    mainMenu.addOption("Alisveris");
    mainMenu.addOption("Cikis");

    vector<Customer> allCustomers;
    vector<Product> allProducts;

    int mainChoice;

    cout << "ONLINE BOOK STORE SYSTEM\n";

    do {
        mainMenu.show();
        mainChoice = mainMenu.getChoice();

        switch (mainChoice) {
        case 1:
            customerMenuLoop(allCustomers);
            break;
        case 2:
            itemMenuLoop(allProducts);
            break;
        case 3:
            shoppingMenuLoop(allCustomers, allProducts);
            break;
        case 4:
            cout << "Program sonlandiriliyor. Iyi gunler!\n";
            break;
        default:
            cout << "Gecersiz secim, lutfen tekrar deneyin.\n";
        }

    } while (mainChoice != 4);

    return 0;
}
