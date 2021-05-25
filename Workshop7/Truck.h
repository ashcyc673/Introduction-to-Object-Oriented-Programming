//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           07/15/2020
//==============================================
// Workshop:   7
// Part:      1
//==============================================

#ifndef WORKSHOP7_TRUCK_H
#define WORKSHOP7_TRUCK_H

#include "MotorVehicle.h"

namespace sdds
{
    class Truck : public MotorVehicle{

        double m_capacity;
        double m_currentCargo;

    public:
        Truck();
        Truck(const char plate[], int year, double capacity , const char address[]);
        bool addCargo(double cargo);
        bool unloadCargo();
        ostream& write(ostream& os) const;
        istream& read(istream& in);
        ~Truck();
    };

    ostream& operator<<(ostream& ostr, const Truck&);
    istream& operator>>(istream& istr, Truck&);

}


#endif //WORKSHOP7_TRUCK_H
