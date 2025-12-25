#include <iostream>
#include <vector>
#include <string>
#include "Customer.h"
#include "Product.h"
#include "Book.h"       
#include "Magazine.h"   
#include "MusicCD.h"   
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


void itemMenuLoop(vector<Product*>& products) {
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
            cout << "\nEklemek istediginiz urun turunu secin:\n";
            cout << "1. Book (Kitap)\n";
            cout << "2. Magazine (Dergi)\n";
            cout << "3. MusicCD (Muzik CD)\n";
            cout << "Secim: ";
            int typeChoice;
            cin >> typeChoice;

            if (typeChoice < 1 || typeChoice > 3) {
                cout << "Gecersiz urun tipi secimi! Ana menuye donuluyor.\n";
                break;
            }

            int id_p;
            string name_p;
            double price_p;

            cout << "\n-- Ortak Bilgiler --\n";
            cout << "ID Giriniz: ";
            cin >> id_p;
            
            cout << "Urun Ismi: ";
            cin.ignore(); 
            getline(cin, name_p); 
            
            cout << "Fiyat: ";
            cin >> price_p;

            
            if (typeChoice == 1) { 
                string author, publisher;
                int page;
                
                cout << "-- Kitap Detaylari --\n";
                cout << "Yazar (Author): "; 
                cin.ignore();
                getline(cin, author);
                
                cout << "Yayinevi (Publisher): "; 
                getline(cin, publisher);
                
                cout << "Sayfa Sayisi: "; 
                cin >> page;

                products.push_back(new Book(id_p, name_p, price_p, author, publisher, page));
                cout << ">> Kitap basariyla eklendi!\n";
            }
            else if (typeChoice == 2) { 
                int issue;
                string type;
                
                cout << "-- Dergi Detaylari --\n";
                cout << "Sayi (Issue): "; 
                cin >> issue;
                
                cout << "Tur (Type): "; 
                cin.ignore(); 
                getline(cin, type);

                products.push_back(new Magazine(id_p, name_p, price_p, issue, type));
                cout << ">> Dergi basariyla eklendi!\n";
            }
            else if (typeChoice == 3) { 
                string singer, type;
                
                cout << "-- CD Detaylari --\n";
                cout << "Sarkici (Singer): "; 
                cin.ignore(); 
                getline(cin, singer);
                
                cout << "Muzik Turu (Type): "; 
                getline(cin, type);

                products.push_back(new MusicCD(id_p, name_p, price_p, singer, type));
                cout << ">> Muzik CD basariyla eklendi!\n";
            }
            break;
        }

        case 2:
        {
            cout << "\n--- URUN LISTESI ---\n";
            if (products.empty()) {
                cout << "Kayitli urun yok.\n";
            }
            else {
                for (const auto& prod : products) {
                    prod->printProperties();
                    cout << "----------------------\n";
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
void shoppingMenuLoop(vector<Customer>& customers, vector<Product*>& products) {
    Menu shopMenu("Shopping Menu");
    shopMenu.addOption("Giris");
    shopMenu.addOption("Urun Ekle");
    shopMenu.addOption("Urun Sil");
    shopMenu.addOption("Tum Urunleri Listele");
    shopMenu.addOption("Alisveris Sepetini Listele ");
    shopMenu.addOption("Bonusu Goster");
    shopMenu.addOption("Bonus Kullan");
    shopMenu.addOption("Siparis Ver");
    shopMenu.addOption("Siparis İptal");
    shopMenu.addOption("Faturayi Goster");
    shopMenu.addOption("Cikis (Geri)");

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
                cout << "ID: " << p->getID() << " - " << p->getName()
                    << " (" << p->getPrice() << " TL)\n";
            }

            cout << "\nSepete eklemek istediginiz Urun ID'sini girin: ";
            int targetId;
            cin >> targetId;

            bool productFound = false;
            for (auto& p : products) {
                if (p->getID() == targetId) {
                    myCart.addProduct(p);
                    cout << p->getName() << " sepete eklendi.\n";
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
                if (p->getID() == pid) {
                    myCart.removeProduct(p);
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
                cout << "ID: " << p->getID() << " | " << p->getName()
                    << " | " << p->getPrice() << " TL\n";
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
    vector<Product*> allProducts;

    allProducts.push_back(new Book(101, "Sefiller", 75.50, "Victor Hugo", "Can Yayinlari", 1500));
    allProducts.push_back(new Magazine(201, "Vogue", 50.0, 12, "Moda"));
    allProducts.push_back(new MusicCD(301, "Thriller", 120.0, "Michael Jackson", "Pop"));
    
    cout << ">> Sistem baslangic verileriyle yuklendi.\n";

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
            for (auto p : allProducts) {
                delete p;
            }
            allProducts.clear();
            break;
        default:
            cout << "Gecersiz secim, lutfen tekrar deneyin.\n";
        }

    } while (mainChoice != 4);

    return 0;
}
