#include <iostream>

using namespace std;

double degreesDriveTurn = 12.13; //change degrees turning HDrive later
double currentDegreesDrive = 0.0;

void rotateHDrive(double leftSpeed, double rightSpeed)
{
    currentDegreesDrive = currentDegreesDrive - (degreesDriveTurn * leftSpeed);
    currentDegreesDrive = currentDegreesDrive + (degreesDriveTurn * rightSpeed);
}

int main()
{
    cout << "Current Degrees: " + to_string(currentDegreesDrive) + "\nTURNING LEFT AT 0.2341 SPEED + TURNING RIGHT AT 0.765 SPEED\n";
    rotateHDrive(0.2341, 0.765);
    cout << "Now at: " + to_string(currentDegreesDrive);
}