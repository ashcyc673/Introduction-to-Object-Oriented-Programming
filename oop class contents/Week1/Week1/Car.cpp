#include <iostream>
#include "Car.h"

using namespace std;


namespace sdds {

	void setCar(struct Car* cr) {
	
		cout << "PLease Eneter the Car information: " << endl;
		cout << "ID: ";
		cin >> cr->id;
		cr->id++;
		cout << "Speed: ";
		cin >> cr->speed;	
	}

	void displayCar(const struct Car* cr) {
	
		cout << "The information for the car is: " << endl;
		cout << "ID: " << cr->id << ", Speed: " << cr->speed << endl;	
	
	}

}