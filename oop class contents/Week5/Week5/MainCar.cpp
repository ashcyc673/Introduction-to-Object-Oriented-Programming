#include <iostream>
#include "Car.h"

using namespace std;
using namespace sdds;

int main() {

	Car mycar("BMW", 75000, 350);
	
	/*
	Car mycar1("Tesla", 35000, 250);
	mycar1.setPassenger();
	mycar.setCar("BMW", 75000, 35000);
	myemptycar1.setCar("", 6500, 98);
	myemptycar2.setCar("Tesla", -6500, 98);
	myemptycar2.setEmpty();
	*/
	
	display(mycar);

	//mycar.increaseSpeed(20);
	mycar += 20;
	display(mycar);

	//mycar.incrementSpeed();
	++mycar;
	display(mycar);

	mycar++;
	display(mycar);

	//display(mycar1);

	return 0;
}