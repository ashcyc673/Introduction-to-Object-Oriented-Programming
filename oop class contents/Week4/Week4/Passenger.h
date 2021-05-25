#ifndef SDDS_Passenger_H
#define SDDS_Passenger_H

namespace sdds {

	const int MAX_NAME = 15;

	class Passenger {
		char name[MAX_NAME + 1];
	public:
		void setName(const char* name);
		char* getName();
	};
}
#endif
