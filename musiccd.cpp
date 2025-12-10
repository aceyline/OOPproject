<<<<<<< HEAD
﻿/*				Berfin SELVİ		-		152120241030
				25.11.2025		MusicCD c++ dosyası							*/
#include <iostream>
=======
﻿#include <iostream>
>>>>>>> ac6e212f065372984a87a8d900b2218b72453139

using namespace std;

class MusicCD {
private:
	string type;
	string singer;
public:


	void PrintInfo() {
		cout << "MusicCD Info: " << "Singer: " << singer << " Type: " << type << endl;
	}

	string getSinger() {
		return singer;
	}

	void setSinger(string s) {
		singer = s;
	}

	string getType() {
		return type;
	}

	void setType(string t) {
		type = t;
	}
};
