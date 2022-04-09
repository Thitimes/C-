#pragma once
#include <string>
#include <vector>
using namespace std;
class TextArt {
public:
	TextArt();
	void printText();
	void modifiedText(string modLine , int lineNo);
	void saveToFile(string fileName);

private:
	vector<string>lines;
};