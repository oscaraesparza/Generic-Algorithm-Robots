//
// Created on 12/16/2018
//

#ifndef CPLUSPLUS_ROBOT_H
#define CPLUSPLUS_ROBOT_H

class Robot{
public:
    Robot();
    int genes[16][5];
    void move();
    void setPower(int p);
    int getPower();

private:
    //string name;
    int powerLevel;
    int totalPowerCollected;
    int numberOfTurns;
};
#endif //CPLUSPLUS_ROBOT_H
