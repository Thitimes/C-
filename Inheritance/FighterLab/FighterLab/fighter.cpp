#include <iostream>
#include "fighter.h"
#include <cstdlib>
#include <ctime>

fighter::fighter(int hp, string name, char job) {
	setHP(hp);
	setName(name);
	ATK_Methods = 0;
	if (job == 'm' || job == 'M') {
		ATK_Methods = 1;
	}
	if (job == 'k' || job == 'K') {
		ATK_Methods = 2;
	}
	if (job == 'n' || job == 'N') {
		ATK_Methods = 3;
	}

}
fighter::~fighter() {

}
void fighter::attack(fighter *f) {
	int health,atk;
	srand((unsigned)time(0));
	
	if (ATK_Methods == 1) {
		atk = (rand() % 20) + 10;
		health = getHP() + 10;
		setHP(health);
		getAttack(f, atk);
		
		
	}
	if (ATK_Methods == 2) {
		atk = (rand() % 30) + 20;
		getAttack(f, atk);
		
	}
	if (ATK_Methods == 3) {
		for (int i = 0; i < 2; i++) {
			atk = (rand() % 20) + 10;
			getAttack(f, atk);
			
		}
	}
}

void fighter::setatk_met(int a) {
	ATK_Methods = a;
}
void fighter::getAttack(fighter *g,int b) {
	int hp;
	hp = g->getHP();
	hp -= b;
	g->setHP(hp);
}
int fighter::getATKMETH() {
	return ATK_Methods;
}