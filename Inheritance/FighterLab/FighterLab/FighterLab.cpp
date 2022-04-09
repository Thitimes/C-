
#include <iostream>
#include "fighter.h"
#include "human.h"
#include <fstream>
using namespace std;
struct TestScore
{
    int studentId;
    float score;
    char grade;
};
TestScore test1[20];
int main()
{
   static const int NAMELEN = 50;
    int hp1, hp2, counter = 0;
    char job1, job2;
    string name1;
    string name2;
    ofstream myfile;
    ifstream rfile;
    bool isAttack = false;
    myfile.open("../battle.txt");
    if (myfile.is_open()) {
        myfile << "Welcome to Arena " << endl;
        myfile.close();
    }
    else {
        cout << "ERROR FILE CAN NOT OPEN \n";
    }
    rfile.open("../battle.txt");
    if (rfile.is_open()) {
        while (!rfile.eof()) {
            getline(rfile, name1);
            cout << name1;

        }
       rfile.close();
    }
    else {
        cout << "ERROR FILE CAN NOT OPEN \n";
    }
    cout << "Enter Player1 Name : ";
    std::getline(cin, name1);
    cout << "Enter Player1 HP(80-100) :";
    cin >> hp1;
    if (hp1 > 100 || hp1 < 80) {
        hp1 = 0;
        cout << "Enter Player1 HP(80-100) :";
        cin >> hp1;
    }
    cout << "Enter Player1 Class \n m = Mage \n k = Knight \n n = Ninja \n";
    cin >> job1;
    cout << "Enter Player2 Name : ";
    cin >> name2;
    cout << "Enter Player2 HP(80-100) :";
    cin >> hp2;
    if (hp2 > 100 || hp2 < 80) {
        hp2 = 0;
        cout << "Enter Player1 HP(80-100) :";
        cin >> hp2;
    }

    cout << "Enter Player2 Class \n m = Mage \n k = Knight \n n = Ninja \n";
    cin >> job2;
    fighter fight1(hp1, name1, job1);
    fighter fight2(hp2, name2, job2);
    myfile.open("../battle.txt", ios::app);
    while (fight1.getHP() > 0 && fight2.getHP() > 0 && counter < 10) {
        
        if (isAttack == false) {
            fight1.attack(&fight2);
           
            if (myfile.is_open()) {
                myfile << fight1.getid() << "Attack " << fight2.getid()  << endl;
                cout << fight1.getid() << " Attack " << fight2.getid()  << endl;
                myfile << fight2.getid() << " have " << fight2.getHP() << " HP Left" << endl;
                cout << fight2.getid() << " have " << fight2.getHP() << " HP Left" << endl;
              
            }
            else {
                cout << "ERROR FILE CAN NOT OPEN \n";
            }
            isAttack = true;
        }
        if (isAttack == true) {
            fight2.attack(&fight1);
            if (myfile.is_open()) {
                myfile << fight2.getid() << "Attack " << fight1.getid() << endl;
                cout << fight2.getid() << " Attack " << fight1.getid() << endl;
                myfile << fight1.getid() << " have " << fight1.getHP() << " HP Left" << endl;
                cout << fight1.getid() << " have " << fight1.getHP() << " HP Left" << endl;
                
            }
            else {
                cout << "ERROR FILE CAN NOT OPEN \n";
            }
            
            isAttack = false;
        }
        counter++;

    }
    if (fight1.getHP() > fight2.getHP()) {
        cout << fight1.getid() << " is the winner! " << endl;
        myfile << fight1.getid() << " is the winner! " << endl;
    }
    else{
        cout << fight2.getid() << " is the winner! " << endl;
        myfile << fight2.getid() << " is the winner! " << endl;
    }
    myfile.close();

   /* const unsigned char isHungry = 0x01;
    const unsigned char isSad = 0x02;
    const unsigned char isMad = 0x04;
    const unsigned char isHappy = 0x08;
    const unsigned char isLaughing = 0x10;
    const unsigned char isAsleep = 0x20;
    const unsigned char isDead = 0x40;
    const unsigned char isCrying = 0x80;
   
    unsigned char me = 0;
    me |= isDead| isLaughing;
    me &= ~isDead;

    std::cout << "I am happy? " << static_cast<bool>(me & isDead) << '\n';
    std::cout << "I am Laughing? " << static_cast<bool>(me & isLaughing) << '\n';*/

    //const unsigned int


    return 0;
}

