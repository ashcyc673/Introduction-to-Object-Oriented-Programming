#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds {

	const int MAX_DESC = 15;

	struct Car {

		char m_model[MAX_DESC + 1];
		double m_price;
		int m_maxspeed;

	};

	void set(char* module);
	void set(double& price);
	void set(int& maxspeed);

	void display(const Car& mycar);

}
#endif
