#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds {

	struct Car {
		int id;
		double speed;
	};


	void setCar(struct Car* cr);

	void displayCar(const struct Car* cr);

}

#endif
