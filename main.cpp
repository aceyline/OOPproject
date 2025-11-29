// main.cpp

#include "Menu.h"
#include <cstdlib> // Konsolu temizlemek için (system fonksiyonu)

// NOT: Normalde bu fonksiyonlar BookstoreApp.cpp içinde olmalıdır.

void clearScreen() {
    // Windows için "cls", Linux/macOS için "clear"
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// --- Ana Menü İşlevi ---
void showMainMenu() {
    // Örnek Ekran Görüntüsü ile aynı seçenekler [cite: 231, 232, 233, 234, 235]
    std::vector<std::string> options = {"Customer", "Item", "Shopping", "Quit"};
    Menu mainMenu("Main Menu", options);

    while (true) {
        clearScreen();
        int choice = mainMenu.getChoice();

        switch (choice) {
            case 1:
                showCustomerMenu();
                break;
            case 2:
                // Ürün Menüsünü çağır
                std::cout << "\n[INFO] Item Menu is called.\n";
                // showItemMenu();
                break;
            case 3:
                showShoppingMenu();
                break;
            case 4:
                std::cout << "\nExiting the Online Bookstore. Goodbye!\n";
                return; // Ana döngüden çık
            default:
                std::cout << "\n[HATA] Invalid selection. Please try again.\n";
                break;
        }
        std::cout << "Press ENTER to continue...";
        std::cin.ignore(10000, '\n');
        std::cin.get();
    }
}

// --- Müşteri Menüsü İşlevi ---
void showCustomerMenu() {
    // Örnek Ekran Görüntüsü ile aynı seçenekler [cite: 237, 238, 239, 240]
    std::vector<std::string> options = {"Add a new customer to the system", "Show the customers in the system", "Back"};
    Menu customerMenu("Customer Menu", options);
    
    // NOT: Gerçek uygulamada customer verileri BookstoreApp sınıfında tutulur.

    while (true) {
        clearScreen();
        int choice = customerMenu.getChoice();

        switch (choice) {
            case 1:
                // addNewCustomer() fonksiyonunu çağır (Gerekli Customer sınıfı implementasyonundan sonra)
                std::cout << "\n--- Add Customer ---\n";
                std::cout << "Customer Name: Ali Kaya (Example)\n"; // Örnek girdi simülasyonu [cite: 242, 243]
                std::cout << "Customer Address: Batikent Mah. No: 4, Eskisehir (Example)\n"; // Örnek girdi simülasyonu [cite: 244]
                std::cout << "[INFO] Customer added successfully (Simulated).\n";
                break;
            case 2:
                // listCustomers() fonksiyonunu çağır
                std::cout << "\n[INFO] Customers listed (Simulated).\n";
                break;
            case 3:
                return; // Ana Menü'ye geri dön
            default:
                std::cout << "\n[HATA] Invalid selection. Please try again.\n";
                break;
        }
        std::cout << "Press ENTER to continue...";
        std::cin.ignore(10000, '\n');
        std::cin.get();
    }
}

// --- Alışveriş Menüsü İşlevi ---
void showShoppingMenu() {
    // Örnek Ekran Görüntüsü ile aynı seçenekler [cite: 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267]
    std::vector<std::string> options = {
        "Login", "Add Product", "Remove Product", "List All Products", 
        "List Shopping Cart", "Show Bonus", "Use Bonus", "Place Order", 
        "Cancel Order", "Show Invoice", "Quit"
    };
    Menu shoppingMenu("Shopping Menu", options);

    // NOT: Gerçek uygulamada, bir Customer login olduktan sonra ShoppingCart'a erişimi olur.
    
    while (true) {
        clearScreen();
        int choice = shoppingMenu.getChoice();

        switch (choice) {
            case 1:
                // handleLogin()
                std::string username, password;
                std::cout << "\nEnter the username: ";
                std::cin >> username; // Örnek: akaya [cite: 269]
                std::cout << "Enter the password: ";
                std::cin >> password; // Örnek: 12345 [cite: 270]
                std::cout << "[INFO] Login attempted with: " << username << ".\n";
                // Login mantığı burada uygulanır (Customer::checkAccount metodu) [cite: 136]
                break;
            // ... Diğer 9 seçenek buraya gelir
            case 11:
                return; // Ana Menü'ye geri dön
            default:
                std::cout << "\n[HATA] Invalid selection. Please try again.\n";
                break;
        }
        std::cout << "Press ENTER to continue...";
        std::cin.ignore(10000, '\n');
        std::cin.get();
    }
}

int main() {
    // Burada BookstoreApp app; app.run(); çağırılabilir.
    // Şimdilik sadece menü fonksiyonunu çağıralım:
    showMainMenu();
    return 0;
}