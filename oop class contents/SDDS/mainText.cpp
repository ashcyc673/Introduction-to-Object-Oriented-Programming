#include "Car.h"
using namespace sdds;

int main()
{
    struct Car myCar;

    setCar(&myCar);
    displayCar(&myCar);

    return 0;
}
