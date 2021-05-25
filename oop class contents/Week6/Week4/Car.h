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
		Car(const Car& copy);
		Car& operator=(const Car& copy);
		void setPassenger(std::istream& is = std::cin);
		void setCar(const char* module, double price, int speed);
		void setEmpty();
		const char* getModule() const;
		double getPrice() const;
		int getSpeed() const;
		int getNmpass() const;
		bool isEmpty() const;
		void displayPassenger() const;
		void display(std::ostream& os = std::cout) const;
		~Car();
	};

	std::ostream& operator<<(std::ostream& os, const Car& s);
	std::istream& operator>>(std::istream& is, Car& s);

}
#endif
