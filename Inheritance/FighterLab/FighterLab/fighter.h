#pragma once
#include "human.h"
class fighter : public human{
public:
	fighter(int, string,char);
	~fighter();
	void attack(fighter *);
	void setatk_met(int);
	void getAttack(fighter *,int);
	int getATKMETH();
protected:
	int ATK_Methods;
};