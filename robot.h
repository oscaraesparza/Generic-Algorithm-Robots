//
// Created on 12/16/2018
//

#ifndef CPLUSPLUS_ROBOT_H
#define CPLUSPLUS_ROBOT_H

class Robot{
public:
    Robot();
    int genes[16][5];
    int map[100];
    int numberOfTurns;
    void move();
    void setPower(int p);
    int getPower();
    int n, s, e, w;

private:
    //string name;
    int powerLevel;
    int totalPowerCollected;
    void genMap();
    void genGenes();
    void useTurn();
};
#endif //CPLUSPLUS_ROBOT_H
