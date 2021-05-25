#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Passenger.h"

namespace sdds {

	const int MAX_DESC = 15;

	class Car {

		char m_module[MAX_DESC + 1];
		double m_price;
		int m_speed;
		Passenger* pass;
		int nmpass;

	public:
		Car();
		Car(const char* module, double price, int speed);
		void setPassenger();
		void setCar(const char* module, double price, int speed);
		void setEmpty();
		char* getModule();
		double getPrice() const;
		int getSpeed() const;
		int getNmpass() const;
		bool isEmpty() const;
		void displayPassenger();
		~Car();
	};

	void display(Car& mycar);
}
#endif
