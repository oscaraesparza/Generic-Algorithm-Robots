//
// Created on 12/16/2018.
//

#include "robot.h"
#include <time.h>   // time
#include <stdlib.h> // srand & rand

Robot::Robot()
{
    /* initialize random seed: */
    srand (time(NULL));
    powerLevel = 5;
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

void Robot::setPower(int p) {
    if(powerLevel == 0)
        powerLevel = p;
    else
        powerLevel += p;
}

void Robot::move(){
    return;
}
int Robot::getPower()
{
    return powerLevel;
}