#include <iostream>
#include <math.h>

using namespace std;

//H-Drive Variables
double degreesDriveTurn = 12.13; //change degrees turning HDrive later
double currentDegreesDrive = 0.0;

//Motor Control Methods
void moveForward(int speed)
{
    //de-activate all motors

    //activate motors with 1 and speed
}

void moveBackward(double speed)
{
    //de-activate all motors

    //activate motor with -1 and speed
}

void moveLeft(double speed)
{
    //de-activate all motors

    //activate middle motor with -1 and speed
}

void moveRight(double speed)
{
    //de-activate all motors

    //activate middle motor with 1 and speed
}

//H-Drive Methods

void rotateHDrive(double leftSpeed, double rightSpeed)
{
    currentDegreesDrive = currentDegreesDrive - (degreesDriveTurn * leftSpeed);
    currentDegreesDrive = currentDegreesDrive + (degreesDriveTurn * rightSpeed);
}

void assignDriveVectorCoords(double xCoord, double yCoord)
{
    //theta angle of vector coords
    double theta = acos(xCoord / (pow(xCoord, double(2.0)) + pow(yCoord, double(2.0))));
    if (xCoord >= 0 && yCoord <= 0)
    {
        theta = theta + M_PI;
    }
    else if (xCoord <= 0 && yCoord <= 0)
    {
        theta = theta + (M_PI / double(2.0));
    }

    if (theta >= (M_PI / 2) && theta <= 3 * (M_PI / 2))
    {
        //move forward callback
        moveForward(abs(xCoord));
    }
    else if (theta > 3 * (M_PI / 2) && theta < 5 * (M_PI / 2))
    {
        //move left callback
        moveLeft(abs(yCoord));
    }
    else if (theta >= 5 * (M_PI / 2) && theta <= 7 * (M_PI / 2))
    {
        //move backward callback
        moveBackward(abs(xCoord));
    }
    else
    {
        //move right callback
        moveRight(abs(yCoord));
    }
}

//Main Methods
int main()
{
    cout << "Current Degrees: " + to_string(currentDegreesDrive) + "\nTURNING LEFT AT 0.2341 SPEED + TURNING RIGHT AT 0.765 SPEED\n";
    rotateHDrive(0.2341, 0.765);
    cout << "Now at: " + to_string(currentDegreesDrive);
}