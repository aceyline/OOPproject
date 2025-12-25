#ifndef MUSICCD_H
#define MUSICCD_H
#include "Product.h"
#include <string>
using namespace std;

class MusicCD : public Product {
private: string type, singer;

public:
	MusicCD(int id, const string& name, double price,
            const string& singer, const string& type);

    string getSinger() const;
    void setSinger(const string& singer);

    string getType() const;
    void setType(const string& type);

    // Override (Ezme) işlemi
    void printProperties() const override;
};
#endif