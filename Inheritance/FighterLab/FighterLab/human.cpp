#include <iostream>
#include <string>
#include "human.h"


human::human() {
	HP = 0;
	id = '/0';
}
human::~human() {

}
string human::getid()const {
	return id;
}
float human::getHP() {
	return HP;
}
void human::setName(string n) {
   /* for (int i = 0; i < NAMELEN; i++) {
        if (n == '\0') {
            return;
        }
        else {
            *(id + i) = *(n + i);
        }
    }*/
    id = n;
}
void human::setHP(int a) {
    HP = a;

}