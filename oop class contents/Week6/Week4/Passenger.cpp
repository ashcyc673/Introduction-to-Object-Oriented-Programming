#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

namespace sdds {

	void Passenger::setName(const char* name) {
		if (name == nullptr || name[0] == '\0') {
			this->name[0] = '\0';
		}
		else {
			strncpy(this->name,name,MAX_NAME);
		}
	}

	char* Passenger::getName() {
		return this->name;
	}	
}