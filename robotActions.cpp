//
// Created on 12/16/2018.
//

#include "robot.h"
#include <time.h>   // time
#include <stdlib.h> // srand & rand
#include <iostream>

using namespace std;

Robot::Robot()
{
    /* initialize random seed: */
    powerLevel = 5;
    numberOfTurns = 0;
    genGenes();
    genMap();
}

void Robot::setPower(int p) {
    powerLevel += p;
}

void Robot::genGenes()
{
    srand ((unsigned)(time(NULL)));
    for(int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 4; j++)
            // random sensor genes
            // 0 = empty, 1 = wall, 2 = battery
            genes[i][j] = (rand() % 3);
        // 3 = N, 4 = E, 5 = S, 6 = W, 7 = rand aka action gene
        genes[i][4] = (rand() % 5) + 3;
    }
}
void Robot::genMap()
{
    srand ((unsigned)(time(NULL)));
    //srand (time(0));
    int place;
    // loops 40 times because 40% of map must be battery
    for(int i = 0; i < 100; i++) {
        map[i] = 0;
    }
    for (int i = 0; i < 40; i++)
    {
        place = (rand() % 100);
        // should keep looping until you find an empty place
        while(map[place] != 0)
            place = (rand() % 100);
        //place battery in empty place
        if(map[place] == 0)
            map[place] = 2;

    }
}
void Robot::move(){
    //using namespace std;
    srand ((unsigned)(time(NULL)));
    int position = (rand() % 100);
    int action = 0;
    map[position] = 9;
    while(getPower() > 0)
    {
        cout << "Map with " << getPower() << " left\n";
        for(int i = 0; i < 100; i++) {
            if((i % 10) == 0)
                cout << endl;
            cout << map[i] << " ";
        }
        //##################Check For Walls#############
        // there is a wall to the north
        if(position < 9)
            n = 1;
        else if(map[position - 10] == 2)
            n = 2; // battery
        else n = 0; // if not a wall or battery then blank space
        // wall to the south
        if(position > 89)
            s = 1;
        else if(map[position + 10] == 2)
            s = 2;
        else s = 0;
        // 9? 19? 29? then there is a wall in the East
        if(((position - 9) % 10) == 0)
            e = 1;
        else if(map[position + 1] == 2)
            e = 2;
        else e = 0;
        // wall to the west
        if((position % 10) == 0)
            w = 1;
        else if(map[position - 1] == 2)
            w = 2;
        else w = 0;

        cout << "\nCurrent Sensors : " << n << e << s << w << endl;
        for(int i = 0; i < 15; i++) {
            if (action == 0) {
                if ((genes[i][0] == n) && (genes[i][1] == e) && (genes[i][2] == s) && (genes[i][3] == w))
                    action = genes[i][4];
            }
            //else break;
            //cout << "After loop : " << i << " Action is " << action << endl;
        }
        if(action == 0)
            action = genes[15][4];
        // time to move
        // 3 = N, 4 = E, 5 = S, 6 = W, 7 = rand aka action gene
        if(action == 7){
            action = (rand() % 4) + 3;
            cout << "\nNo Match Found so doing action " << action<< endl;
        }

        if(action == 3) {
            if (n == 1) {
                setPower(-1);
                cout << "\nHit a wall\n";
            }

            else if (n == 2) {
                setPower(-1);
                map[position] = 0;
                position = position - 10; // move north
                setPower(5); // consumed a battery
                map[position] = 0; //gets rid of battery
            }
            else {
                map[position] = 0;
                position = position - 10;
                setPower(-1);
            }
            map[position] = 9;
        }

        if(action == 4) {
            if (e == 1){
                setPower(-1);
                cout << "\nHit a wall\n";
            }
            else if (e == 2) {
                setPower(-1);
                map[position] = 0;
                position = position + 1; // move north
                setPower(5); // consumed a battery
                map[position] = 0; //gets rid of battery
            }
            else {
                map[position] = 0;
                position++;
                setPower(-1);
            }
            map[position] = 9;
        }

        if(action == 5) {
            if (s == 1){
                setPower(-1);
                cout << "\nHit a wall\n";
            }
            else if (e == 2) {
                setPower(-1);
                map[position] = 0;
                position = position + 10; // move north
                setPower(5); // consumed a battery
                map[position] = 0; //gets rid of battery
            }
            else {
                map[position] = 0;
                position = position + 10;
                setPower(-1);
            }
            map[position] = 9;
        }

        if(action == 6 ) {
            if (w == 1){
                setPower(-1);
                cout << "\nHit a wall\n";
            }
            else if (w == 2) {
                setPower(-1);
                map[position] = 0;
                position = position - 1; // move north
                setPower(5); // consumed a battery
                map[position] = 0; //gets rid of battery
            }
            else {
                map[position] = 0;
                position--;
                setPower(-1);
            }
            map[position] = 9;
        }
        useTurn();
        //setPower(-1);
        // now we got the sensors working
    }
}
int Robot::getPower()
{
    return powerLevel;
}

void Robot::useTurn(){
    numberOfTurns++;
}