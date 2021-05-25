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
	}

	Car::Car(const char* module, double price, int speed) {
		setCar(module, price, speed);
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
	double Car::getPrice() const {
		return m_price;
	}
	int Car::getSpeed() const {
		return m_speed;
	}

	bool Car::isEmpty() const {
		return (m_module == nullptr || m_module[0] == '\0' || m_price < 0 || m_speed < 0);
	}

	void Car::increaseSpeed(int spd) {
		this->m_speed += spd;
	}

	Car& Car::operator+=(int spd) {
		this->m_speed += spd;
		return *this;
	}

	void Car::incrementSpeed() {
		this->m_speed++;
	}

	Car& Car::operator++() { //prefix
		this->m_speed++;
		return *this;
	}

	Car Car::operator++(int) { //postfix
		Car c = *this;  // save the original
		++(*this);          // call the pre-fix operator
		return c;           // return the original
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