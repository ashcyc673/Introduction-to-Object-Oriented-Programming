#include <iostream>
#include "Car.h"

using namespace std;
using namespace sdds;

int main() {

	Car* mycarlist = nullptr;
	int nmcars = 0;

	cout << "How many cars do you wnat to enter: ";
	cin >> nmcars;

	mycarlist = new Car[nmcars];

	for (int i = 0; i < nmcars; i++) {
		set(mycarlist[i].m_model);
		set(mycarlist[i].m_price);
		set(mycarlist[i].m_maxspeed);
	}

	for (int i = 0; i < nmcars; i++) {
		display(mycarlist[i]);
	}
	
	delete[] mycarlist;

	return 0;
}