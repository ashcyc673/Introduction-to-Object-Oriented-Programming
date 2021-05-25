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
		nmpass = 0;
	}

	Car::Car(const char* module, double price, int speed) {
		setCar(module, price, speed);
	}

	Car::Car(const Car& copy) {
		// shallow copies
		m_price = copy.m_price;
		strcpy(m_module, copy.m_module);
		nmpass = copy.nmpass;

		// allocate dynamic memory for grades
		if (copy.pass != nullptr) {
			pass = new Passenger[nmpass];
			// copy data from the source resource 
			// to the newly allocated resource
			for (int i = 0; i < nmpass; i++)
				pass[i] = copy.pass[i];
		}
		else {
			pass = nullptr;
		}
	}

	Car& Car::operator=(const Car& copy) {
	
		if (this != &copy) {
			// shallow copies
			m_price = copy.m_price;
			strcpy(m_module, copy.m_module);
			nmpass = copy.nmpass;

			// allocate dynamic memory for grades
			if (copy.pass != nullptr) {
				pass = new Passenger[nmpass];
				// copy data from the source resource 
				// to the newly allocated resource
				for (int i = 0; i < nmpass; i++)
					pass[i] = copy.pass[i];
			}
			else {
				pass = nullptr;
			}
		}
		return *this;
	}


	void Car::setPassenger(istream& is) {
		char name[15];

		if (pass) {
			delete[] pass;
		}

		cout << "How many passengers?: ";
		is >> nmpass;
		pass = new Passenger[nmpass];

		for (int i = 0; i < nmpass;i++) {
			cout << "Please enter the name of passenger number " << i + 1 << " : ";
			is >> name;
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

	const char* Car::getModule() const{
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

	void Car::displayPassenger() const{
		for (int i = 0; i < getNmpass(); i++) {
			cout << "Passenger " << i + 1 << " " << pass[i].getName() << endl;
		}
	}

	Car::~Car() {
		cout << "Destrctor of " << this->getModule() << " is being called" << endl;
		delete[] pass;	
	}

	void Car::display(std::ostream& os) const
	{
		if (isEmpty()) {
			os << "Car is Empty, no details to provide" << endl;
		}
		else {
			os << "Car Details:" << endl;
			os << "Module: " << getModule() << endl;
			os << "Price: " << getPrice() << endl;
			os << "Speed: " << getSpeed() << endl;
			displayPassenger();
		}
	}

	std::ostream& operator<<(std::ostream& os, const Car& s) {
		s.display(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Car& s) {
		s.setPassenger();
		return is;
	}
}