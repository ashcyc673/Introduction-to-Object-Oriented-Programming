#include <iostream>
#include "Car.h"

using namespace std;

namespace sdds {

	void set(char* module)
	{
		cout << "Enter Car Module: ";
		cin.width(MAX_DESC + 1);
		cin >> module;
	}

	void set(double& price)
	{
			cout << "Enter Car price: ";
			cin >> price;
	}

	void set(int& maxspeed)
	{		
			cout << "Enter Car speed: ";
			cin >> maxspeed;
	}

	void display(const Car& mycar)
	{
		cout << "Car Details:" << endl;
		cout << " Module: " << mycar.m_model  << endl;
		cout << "Price: " << mycar.m_price << endl;
		cout << "Speed: " << mycar.m_maxspeed << endl;
	}
}