#pragma once
#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

class Team
{
public:
	Team();
	~Team();
	void removeStudent(int);
	void print();
	void shrinkSize();
	void find_smallest();
	int teamMember;
	string teamName;
	Student* studentInfo;
};