#include <iostream>
#include "Car.h"

using namespace std;

namespace sdds
{

    void setCar(struct Car* cr)
    {
        cout << "Please enter the car information: " << endl;
        cout << "ID: ";
        cin >> cr->id;
        cout << "Speed: ";
        cin >> cr->speed;
    }

    void displayCar(const struct Car* cr)
    {
        cout << "The information for the car is: " << endl;
        cout << "ID: " << cr->id << ", Speed: " << cr->speed << endl;

    }
}