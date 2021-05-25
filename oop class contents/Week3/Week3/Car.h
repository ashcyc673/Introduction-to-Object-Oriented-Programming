#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds {

	const int MAX_DESC = 15;

	class Car {

		char m_module[MAX_DESC + 1];
		double m_price;
		int m_speed;

	public:
		void setCar(const char* module, double price, int speed);
		void setEmpty();
		char* getModule();
		double getPrice();
		int getSpeed();
		bool isEmpty();

	};

	void display(Car& mycar);
	

}
#endif
