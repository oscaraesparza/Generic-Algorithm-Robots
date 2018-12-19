#include <iostream>
#include "robot.h"  //robot class

using namespace std;
int main() {
    int generations;
    const int numberOfRobots = 200;
    bool simutation = true;
    int map[10][10] = {0};
    cout << "Lets get Evolving" << std::endl;
    cout << "How many generations would you like to simulate? : ";
    cin >> generations;
    Robot robotCollection[numberOfRobots];

    // main simulator group
    while(simutation)
    {
        // creating 200 robots
        for (int i = 0; i < numberOfRobots; i++)
        {
            robotCollection[i] = Robot();
        }
        // for testing power
        for (int i = 0; i < numberOfRobots; i++)
        {
            cout << robotCollection[i].getPower() << " ";
        }
        for (int k = 0; k < numberOfRobots; k++)
        {
            cout << "Robot : " << k << endl;
            for(int i = 0; i < 16; i++) {
                for (int j = 0; j < 5; j++) {
                    // random sensor genes
                    cout << robotCollection->genes[i][j] << " ";
                }
                cout << endl;
            }
        }
        simutation = false;
    }
    return 0;
}