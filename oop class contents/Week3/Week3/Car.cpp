#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Car.h"


using namespace std;

namespace sdds {

	void Car::setCar(const char* module, double price, int speed) {

		if (module == nullptr || module[0] == '\0' ||price < 0 || speed < 0) {
			setEmpty();
		}
		else {		
			strncpy(m_module, module,15);
			m_price = price;
			m_speed = speed;		
		}
	}

	void Car::setEmpty() {
		m_module[0] = '\0';
		m_price = 0;
		m_speed = 0;
	}

	char* Car::getModule() {
		return m_module;
	}
	double Car::getPrice() {
		return m_price;
	}
	int Car::getSpeed() {
		return m_speed;
	}
	bool Car::isEmpty() {
		return (m_module == nullptr || m_module[0] == '\0' || m_price < 0 || m_speed < 0);
	}


	void display(Car& mycar)
	{
		if (mycar.isEmpty()) {
			cout << "Car is Empty, no details to provide" << endl;
		}
		else {
			cout << "Car Details:" << endl;
			cout << "Module: " << mycar.getModule() << endl;
			cout << "Price: " << mycar.getPrice() << endl;
			cout << "Speed: " << mycar.getSpeed() << endl;
		}
	}
}
