#pragma once
#include <string>
using namespace std;
class human {
public:
	human();
	~human();
	string getid()const;
	float getHP();
	void setName(string);
	void setHP(int);

protected:
	string id;
	static const int NAMELEN = 50;
	int HP;
};