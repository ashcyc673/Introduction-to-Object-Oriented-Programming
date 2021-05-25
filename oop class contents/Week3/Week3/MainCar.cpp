#include <iostream>
#include "Car.h"

using namespace std;
using namespace sdds;

int main() {

	Car mycar;
	Car myemptycar1;
	Car myemptycar2;
	Car myemptycar3;
	
	mycar.setCar("BMW",75000,35000);
	myemptycar1.setCar("",6500,98);
	myemptycar2.setCar("Tesla", -6500, 98);
	myemptycar2.setEmpty();

	display(mycar);
	display(myemptycar1);
	display(myemptycar2);
	display(myemptycar3);


	return 0;
}