#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

#define WIDTH 10
#define HEIGHT 10
class Map
{
public:
	Map();
	~Map();
	void ReadMap();
	void PrintMap();
	int getmaxTurn();
	bool CheckValid(int , int);
	void MovePlayer(int Posx, int Posy);
	bool WinCon();
	int playerPosX = 0;
	int playerPosY = 0;
	int GoalPosX = 0;
	int GoalPosY = 0;

private:
	
	int maparr[WIDTH][HEIGHT];
	int maxturn = 4;
	
};

