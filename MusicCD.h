<<<<<<< HEAD
/*				Berfin SELVÝ		-		152120241030
				25.11.2025		MusicCD head dosyasý							*/
=======
>>>>>>> ac6e212f065372984a87a8d900b2218b72453139
#ifndef MUSICCD_H
#define MUSICCD_H
#include <string>
using namespace std;
class MusicCD {
private: string type, singer;

public:
	MusicCD(string singerName, string musicType);

	void setType(string t);
	void setSinger(string s);
	string getType();
	string getSinger();
	void printProperties();
};
#endif