#include <iostream>
#include <fstream>
#include "TextArtModifier.h"

TextArt::TextArt() {
	string line;
	fstream myfile;
	myfile.open("fonts.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line)) {	
			lines.push_back(line);
		}	
		myfile.close();
	}
}
void TextArt::printText() {
	for (int i = 0; i < lines.size(); i++) {
		cout << lines[i] << endl;
	}
}
void TextArt::modifiedText(string modLine, int lineNo) {
	
	if (lineNo < lines.size()) {
		lines[lineNo] = modLine;
	}
	else {
		for (int i = lines.size(); i < lineNo; i++) {
			lines.push_back(" \n");
		}
		lines[lineNo-1] = modLine;
	}
}
void TextArt::saveToFile(string fileName) {
	ofstream myfile(fileName);
	if (myfile.is_open())
	{
		for (int i = 0; i < lines.size(); i++) {
			myfile << lines[i] << endl;
		}
		myfile.close();
	}
}
int main()
{
	TextArt textArt;
	textArt.printText();
	cout << "----------------- Change line no 3 ------------------------- " << endl;
	textArt.modifiedText("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 3);
	textArt.printText();
	cout << "----------------- Change line no 8 ------------------------- " << endl;
	textArt.modifiedText(" 888888888888888888888888888 ", 8);
	textArt.printText();
	textArt.saveToFile("modFont.txt");
	system("pause");
	return 0;

}


