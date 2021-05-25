#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds {

	const int MAX_DESC = 15;

	class Car {

		char m_module[MAX_DESC + 1];
		double m_price;
		int m_speed;

	public:
		Car();
		Car(const char* module, double price, int speed);
		void setCar(const char* module, double price, int speed);
		void setEmpty();
		char* getModule();
		double getPrice() const;
		int getSpeed() const;
		bool isEmpty() const;
		void increaseSpeed(int spd);
		void incrementSpeed();
		Car& operator+=(int spd);
		Car& operator++(); //prefix
		Car operator++(int); //postfix
	};

	void display(Car& mycar);
}
#endif
