#include <iostream>
#include <fstream>
#include "Team.h"
#include "Student.h"

using namespace std;
int main()
{
    int tmaxamount = 0, biggest = 0;
    ifstream myfile;
    myfile.open("student.txt");

    if (!myfile.is_open()) {
        cout << "Error cannot find file";
    }
    else {
        myfile >> tmaxamount;
        Team* teams = new Team[tmaxamount];
        for (int i = 0; i < tmaxamount; i++) {
            myfile >> teams[i].teamName;
            myfile >> teams[i].teamMember;
            if (teams[i].teamMember > biggest) {
                biggest = teams[i].teamMember;
            }
            teams[i].studentInfo = new Student[teams[i].teamMember];
            for (int j = 0; j < teams[i].teamMember; j++) {
              myfile >> teams[i].studentInfo[j].name;
              myfile >> teams[i].studentInfo[j].grade;

            }
           
            teams[i].print();
        }
        myfile.close();
      /*  teams[0].find_smallest();
        teams[1].find_smallest();
        teams[2].find_smallest();
        teams[0].print();
        teams[1].print();
        teams[2].print();*/
        for (int i = 0; i < tmaxamount; i++) 
        {
            for (int j = 0; j < biggest; j++) {
                teams[i].find_smallest();
                teams[i].print();
            }

        }
        delete[] teams;
    }
    
}

