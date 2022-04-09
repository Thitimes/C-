#pragma once
#include <iostream>
#include "song.h"

struct Node {
	Song data;
	struct Node* next;
};
class PlayList
{
public:
	PlayList();
	~PlayList();
	void AddSong(const Song& s);
	void ShowAll() const;
	void Play(int num = -1);
	bool DeleteSong(const Song& s);
	void ShowStatus() const;


private:
	Node* head;
	Node* tail;
	Node* currentSong;
	int currSong;
	int totalSong;
	int num;
};

