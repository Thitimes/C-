
#include <iostream>
#include <ReadWriteFile.h>
#include <RandomMap.h>


int main()
{
   //int playerturn = 0;
   /* int Inputx = 0;
    int Inputy = 0;
    Map test;
    test.ReadMap();
    test.PrintMap();
    while (playerturn != test.getmaxTurn() && !test.WinCon())
    {
       cout << "Choose Player X position that you what to go" << endl;
        cin >> Inputx;
        cout << "Choose Player Y position that you what to go" << endl;
        cin >> Inputy;

        if (test.CheckValid(Inputx, Inputy)) {
            test.MovePlayer(Inputx, Inputy);
            playerturn++;
            cout << "Player Current Turn = "  <<playerturn << endl;
        }
        else {
            cout << "Your Input is Invalid Please Enter Against" << endl;
        }
        test.PrintMap();
    }
    if (test.WinCon()) {
        cout << "You Escape out alive " << endl;
    }
    else {
        cout << "You didn't Escape out alive " << endl;
    }*/
    
    RandomMap test;
    vector<int> path;
    test.fillMap();
    test.setPlayerGoalDistance();
    test.randomPlayerGoal();
    test.PrintMap();
    test.findAvilablePath(test.pPosx, test.pPosy, path);
    test.shortestPath();
   // test.makeground();
   
}


