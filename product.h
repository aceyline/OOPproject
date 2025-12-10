<<<<<<< HEAD
/*				Berfin SELVÝ		-		152120241030
				25.11.2025		Product head dosyasý							*/
=======
>>>>>>> ac6e212f065372984a87a8d900b2218b72453139
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
using namespace std;

class Product {
protected :
	int id;
	double price;
	string name;
public:
	Product (int id = 0, double price = 0.0, string name = "");
	
	virtual void printProperties() const = 0;
	
};
#endif