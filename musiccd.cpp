#include <iostream>

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
