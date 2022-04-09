#include <ReadWriteFile.h>
Map::Map(){
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			maparr[i][j] = 0;
		}
	}
}
Map::~Map() {


}
void Map::ReadMap() {
	ifstream file;
	file.open("Sample.txt");
	if (!file.is_open()) {
		return;
	}
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			file >> maparr[i][j];
			if (maparr[i][j] == 3) {
				playerPosX = j;
				playerPosY = i;

			}
			if (maparr[i][j] == 2) {
				GoalPosX = j;
				GoalPosY = i;

			}
		}
	}
	file.close();
}
void Map::PrintMap() {
	cout << "  0123456789 " << endl << endl;
	for (int i = 0; i < HEIGHT; i++) {
		cout << i << " ";
		for (int j = 0; j < WIDTH; j++) {
			
			if (maparr[i][j] == 0) {
				cout << " ";
			}
			else {
				std::cout << maparr[i][j];
			}
		}
		std::cout << std::endl;
	}
}
int Map::getmaxTurn() {
	return maxturn;
}
bool Map::CheckValid(int Posx, int Posy) {
	int tempx = 0;
	int tempy = 0;
	tempx =abs( Posx - playerPosX);
	tempy = abs(Posy - playerPosY);
	cout << "Tempx = " << tempx << " Tempy = " << tempy << endl;
	if (Posx > 0 && Posy > 0) {
		if (tempx + tempy <= 4 ) {
			if (maparr[Posy + 1][Posx] == 1) {
				cout << "in" << endl;
				return true;
			}
		}
	}
	return false;
}

void Map::MovePlayer(int Posx, int Posy)
{
	
		maparr[playerPosY][playerPosX] = 0;
		maparr[Posy][Posx] = 3;
		playerPosX = Posx;
		playerPosY = Posy;
	

}

bool Map::WinCon() {
	if (playerPosX == GoalPosX && playerPosY == GoalPosY) {
		return true;
	}
	return false;
}

