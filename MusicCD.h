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