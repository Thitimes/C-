#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include "HT.h"

int main()
{
    int tableSize = 97;
    //for print 

    int hashSize = 0;
    int numRow = 0;
    float avgLenght = 0;
    int maxLenght = 0;
    int missCount = 0;

    ifstream myfile;
   
    string word;
    string missWord[10000];
    //for input
    int wordCount;
    string dictName;
    string wordName;

    cout << "Enter word count of file : ";
    cin >> wordCount;

    cout << "Enter dict file name  with .txt: ";
    cin >> dictName;

    cout << "Enter word file name with .txt : ";
    cin >> wordName;


    Hash dict(wordCount);
    myfile.open(dictName);

    if (!myfile.is_open()) {
        cout << "Error cannot find file";
    }
    else {
        clock_t tStart = clock();
        while (getline(myfile, word)) {
            // myfile >> word;
            if (word.length() == 0) {
                break;
            }
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            dict.insertItem(word);
            
        }   
        cout << "Number of entries = " << dict.getEntrie() << endl;
        cout << "Size of Hash Table = " << dict.getSize() << endl;
        cout << "Number of row in use  = " << dict.getSize() << endl;
        cout << "Average list length = " << dict.avgLength() << endl;
        cout << "Maximum list length = " << dict.LongestChain() << endl;
        cout << "Time Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
    }
    myfile.close();
    
    myfile.open(wordName);
    if (!myfile.is_open()) {
        cout << "Error cannot find file";
    }
    else {
        clock_t tStart = clock();
        for (int i = 0; i < wordCount; i++) {
            getline(myfile, word);
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (!dict.contains(word)) {
                missWord[i] = word;
                missCount++;
            }          
        }
        cout << "This is a lne of text that has a missspelling in it." << endl;
        for (int i = 0; i < missCount; i++) {
            cout << "\t word not found: " << missWord[i] << endl;
        }
        cout << "Time to check words = " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
    }
   
    myfile.close();
    return 0;
}

