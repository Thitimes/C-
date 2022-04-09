#pragma once
#define WIDTH 10
#define HEIGHT 10
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class RandomMap
{
public:
	RandomMap();
	~RandomMap();
	void fillMap();
	void setPlayerGoalDistance();
	void randomPlayerGoal();
	void setPlayerMaxTurn();
	void PrintMap();
	void findAvilablePath(int,int, vector<int>);
	void shortestPath();
	void saveMap(string);
	void makeground();
	int mapRandom[HEIGHT][WIDTH];
	int playerMaxTurn;
	int playerGoalDistance;
	int pPosx = 0, pPosy = 0, gPosx = 0, gPosy = 0;
	vector<vector<int>> availablepath;
	bool isGoal = false;
};


