#include <iostream>
#include "robot.h"  //robot class

using namespace std;
int main() {
    int generations;
    const int numberOfRobots = 200;
    bool simutation = true;
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
        for (int i = 0; i < 1; i++)
        {
            robotCollection[i].move();
        }
        cout << "\nDisplaying Genese : \n";
        for(int i = 0; i < 16; i++) {
            for (int j = 0; j < 5; j++) {
                // random sensor genes
                cout << robotCollection[1].genes[i][j] << " ";
            }
            cout << endl;
        }
        /*
        // for testing power
        for (int i = 0; i < numberOfRobots; i++)
        {
            cout << robotCollection[i].getPower() << " ";
        }
         */
        // testing genes
        /*
        for (int k = 0; k < 1; k++)
        {
            cout << "\nRobot : " << k << endl;
            cout << "Displaying the map : ";
            for(int i = 0; i < 100; i++) {
                if((i % 10) == 0)
                    cout << endl;
                cout << robotCollection[k].map[i] << " ";
            }

            cout << "\nDisplaying Genese : \n";
            for(int i = 0; i < 16; i++) {
                for (int j = 0; j < 5; j++) {
                    // random sensor genes
                    cout << robotCollection[k].genes[i][j] << " ";
                }
                cout << endl;
            }
        }*/
        simutation = false;
    }
    return 0;
}
