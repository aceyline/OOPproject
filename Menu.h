#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>

class Menu {
private:
    std::string title;
    std::vector<std::string> options;

public:
    // Kurucu (Constructor)
    Menu(const std::string& t, const std::vector<std::string>& opts)
        : title(t), options(opts) {}

    // Menüyü Ekrana Bastırma Metodu
    void display() const {
        std::cout << "\n--- " << title << " ---\n";
        for (size_t i = 0; i < options.size(); ++i) {
            std::cout << i + 1 << ". " << options[i] << "\n";
        }
        std::cout << "Choose one: ";
    }

    // Kullanıcıdan Seçim Alma Metodu
    int getChoice() const {
        int choice;
        display(); // Menüyü göster
        if (!(std::cin >> choice)) {
            // Hata Kontrolü: Geçersiz giriş (örn. harf girilmesi)
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            return -1; // Hatalı seçim
        }
        if (choice < 1 || choice > options.size()) {
            return -1; // Geçersiz aralıkta seçim
        }
        return choice;
    }
};

#endif // MENU_H
