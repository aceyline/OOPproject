#include "MusicCD.h"
#include <iostream>
using namespace std;

MusicCD::MusicCD(int id, const string& name, double price,
                 const string& singer, const string& type)
    : Product(id, name, price), singer(singer), type(type) {
}

string MusicCD::getSinger() const { return singer; }
void MusicCD::setSinger(const string& singer) { this->singer = singer; }

string MusicCD::getType() const { return type; }
void MusicCD::setType(const string& type) { this->type = type; }

void MusicCD::printProperties() const {
    cout << "  MUSIC CD   " << endl;
    Product::printProperties();
    cout << "Singer: " << singer << endl;
    cout << "Type: " << type << endl;
}