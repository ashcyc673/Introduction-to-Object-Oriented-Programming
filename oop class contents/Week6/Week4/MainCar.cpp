#include <iostream>
#include "Car.h"

using namespace std;
using namespace sdds;

int main() {

	Car mycar("BMW",75000,350);
	
	cin >> mycar;

	Car copycar(mycar);
	Car copycar1 = mycar;
	
	cout << mycar;
	cout << copycar;
	cout << copycar1;

	return 0;
}