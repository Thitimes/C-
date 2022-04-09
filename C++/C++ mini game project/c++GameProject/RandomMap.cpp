#include <RandomMap.h>

RandomMap::RandomMap() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			mapRandom[i][j] = 0;
		}
	}
	playerMaxTurn = 0;
	playerGoalDistance = 0;
}


RandomMap::~RandomMap() {

}

void RandomMap::fillMap() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 0 || i == 9) {
				mapRandom[i][j] = 1;
		}
			else if (j == 0 || j == 9) {
				mapRandom[i][j] = 1;
			}
		}
	}
}

void RandomMap::setPlayerGoalDistance() {
	srand((unsigned)time(0));
	int randomNumber;
		randomNumber = (rand() % 3);
		playerGoalDistance = ((WIDTH + HEIGHT) / 3) + randomNumber;
}
void RandomMap::randomPlayerGoal() {
	bool ranSuccess = false;
	int tempx, tempy;
	pPosx = (rand() % 8) + 1;
	pPosy = (rand() % 8) + 1;
	mapRandom[pPosy][pPosx] = 3;
	
	while (ranSuccess != true) {
		gPosx = (rand() % 8) + 1;
		gPosy = (rand() % 8) + 1;

		tempx = abs(pPosx - gPosx);
		tempy = abs(pPosy - gPosy);

		if (tempx + tempy == playerGoalDistance) {
			mapRandom[gPosy][gPosx] = 2;
			ranSuccess = true;
		}

	}
}
void RandomMap::setPlayerMaxTurn() {
	playerMaxTurn = (playerGoalDistance / 3) + 1;
}
void RandomMap::PrintMap() {
	cout << "  0123456789 " << endl << endl;
	for (int i = 0; i < HEIGHT; i++) {
		cout << i << " ";
		for (int j = 0; j < WIDTH; j++) {

			if (mapRandom[i][j] == 0) {
				cout << " ";
			}
			else {
				std::cout << mapRandom[i][j];
			}
		}
		std::cout << std::endl;
	}
}
void RandomMap::findAvilablePath(int posX,int posY, vector<int> path) {
	
	if (isGoal != true) {
		vector<int> path1 = path;
		vector<int> path2 = path;
		vector<int> path3 = path;
		vector<int> path4 = path;
		if (path.size() == 8) {
			availablepath.push_back(path);
			return;
		}
		if (mapRandom[posY + 1][posX] == 1 || mapRandom[posY + 1][posX] == 3) {
			return;
		}
		else if (mapRandom[posY + 1][posX] == 0) {
			//cout << "stack" << endl;
			path1.push_back(posY + 1);
			path1.push_back(posX);

			findAvilablePath(posX, posY + 1, path1);

		}
		else if (mapRandom[posY + 1][posX] == 2) {
			isGoal = true;
			//cout << "stack2" << endl;
			path1.push_back(posY + 1);
			path1.push_back(posX);
			availablepath.push_back(path1);
			return;
			
		}
		if (mapRandom[posY - 1][posX] == 1 || mapRandom[posY - 1][posX] == 3) {
			return;
		}
		else if (mapRandom[posY - 1][posX] == 0) {
			//cout << "stack3" << endl;
			path2.push_back(posY - 1);
			path2.push_back(posX);
			findAvilablePath(posX, posY - 1, path2);

		}
		else if (mapRandom[posY - 1][posX] == 2) {
			//cout << "stack4" << endl;
			isGoal = true;
			path2.push_back(posY + 1);
			path2.push_back(posX);
			availablepath.push_back(path2);
			return;

		}
		if (mapRandom[posY][posX + 1] == 1 || mapRandom[posY][posX + 1] == 3) {
			return;
		}
		else if (mapRandom[posY][posX + 1] == 0) {
			//cout << "stack5" << endl;
			path3.push_back(posY);
			path3.push_back(posX + 1);
			findAvilablePath(posX + 1, posY, path3);

		}
		else if (mapRandom[posY][posX + 1] == 2) {
		//	cout << "stack6" << endl;
			isGoal = true;
			path3.push_back(posY + 1);
			path3.push_back(posX);
			availablepath.push_back(path3);
			return;

		}
		if (mapRandom[posY][posX - 1] == 1 || mapRandom[posY][posX - 1] == 3) {
			return;
		}
		else if (mapRandom[posY][posX - 1] == 0) {
		//	cout << "stack7" << endl;
			path4.push_back(posY);
			path4.push_back(posX - 1);
			findAvilablePath(posX - 1, posY, path4);

		}
		else if (mapRandom[posY][posX - 1] == 2) {
		//	cout << "stack8" << endl;
			isGoal = true;
			path4.push_back(posY + 1);
			path4.push_back(posX);
			availablepath.push_back(path4);
			return;

		}
		
	}

}
void RandomMap::shortestPath() {
	int tempX = 0, tempX2 = 0, tempY = 0, tempY2 = 0, size = 0, index = 0;
	size = availablepath.size();
	tempX = abs(availablepath[0][availablepath[0].size() - 1] - pPosx);
	tempY = abs(availablepath[0][availablepath[0].size() - 2] - pPosy);
	for (int i = 1; i < size; i++) {


		tempX2 = abs(availablepath[i][availablepath[i].size() - 1] - pPosx);
		tempY2 = abs(availablepath[i][availablepath[i].size() - 2] - pPosy);


		if (tempX + tempY > tempX2 + tempY2) {
			index = i;
			tempX = abs(availablepath[i][availablepath[i].size() - 1] - pPosx);
			tempY = abs(availablepath[i][availablepath[i].size() - 2] - pPosy);
		}
	}
	vector<int> shortestPath = availablepath[index];
	mapRandom[shortestPath[shortestPath.size() - 2] + 1][shortestPath[shortestPath.size() - 1]] = 1;
	cout << shortestPath[shortestPath.size() - 2] << endl;
	cout << shortestPath[shortestPath.size() - 1] << endl;


}
void RandomMap::saveMap(string fileName) {

	ofstream file;
	file.open(fileName);
	if (!file.is_open()) {
		return;
	}
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			file << mapRandom[i][j];
		}
		file << endl;
	}
	file.close();
}
void RandomMap::makeground() {
	mapRandom[pPosy +1][pPosx] = 1;
	mapRandom[pPosy +1][pPosx+1] = 1;
	mapRandom[pPosy +1][pPosx-1] = 1;
}