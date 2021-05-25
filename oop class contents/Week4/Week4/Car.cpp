#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds {

	Car::Car() {

		m_module[0] = '\0';
		m_price = -1;
		m_speed = -1;
		pass = nullptr;
	}

	Car::Car(const char* module, double price, int speed) {
		setCar(module, price, speed);
	}

	void Car::setPassenger() {
		char name[15];

		if (pass) {
			delete[] pass;
		}

		cout << "How many passengers?: ";
		cin >> nmpass;
		pass = new Passenger[nmpass];

		for (int i = 0; i < nmpass;i++) {
			cout << "Please enter the name of passenger number " << i + 1 << " : ";
			cin >> name;
			pass[i].setName(name);
		}
	}

	void Car::setCar(const char* module, double price, int speed) {

		if (module == nullptr || module[0] == '\0' || price < 0 || speed < 0) {
			setEmpty();
		}
		else {
			strncpy(m_module, module, 15);
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
	double Car::getPrice() const{
		return m_price;
	}
	int Car::getSpeed() const{
		return m_speed;
	}
	int Car::getNmpass() const {
		return nmpass;
	}
	bool Car::isEmpty() const {
		return (m_module == nullptr || m_module[0] == '\0' || m_price < 0 || m_speed < 0);
	}

	void Car::displayPassenger() {
		for (int i = 0; i < getNmpass(); i++) {
			cout << "Passenger " << i + 1 << " " << pass[i].getName() << endl;
		}
	}

	Car::~Car() {
		cout << "Destrctor of " << this->getModule() << " is being called" << endl;
		delete[] pass;	
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
			mycar.displayPassenger();
		}
	}
}