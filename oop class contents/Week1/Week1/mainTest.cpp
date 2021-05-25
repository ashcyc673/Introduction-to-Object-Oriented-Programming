#include "Car.h"
using namespace sdds;

int main() {

	struct Car mycar = {0,0.0};

	setCar(&mycar);
	displayCar(&mycar);

	return 0;
}