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

#ifndef WORKSHOP7_MOTORVEHICLE_H
#define WORKSHOP7_MOTORVEHICLE_H
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;


namespace sdds
{
    const int MAX_PLATE = 32;
    const int MAX_ADDRESS = 64;

    class MotorVehicle{
        char m_licPlate[MAX_PLATE + 1];
        char m_address[MAX_ADDRESS + 1];
        int m_year;

    public:
        MotorVehicle();
        MotorVehicle(const char plate[], int year);
        void moveTo(const char address[]);
        ostream& write(ostream& os) const;
        istream& read(istream& in);
        ~MotorVehicle();
    };
    ostream& operator<<(ostream& ostr, const MotorVehicle&);
    istream& operator>>(istream& istr, MotorVehicle&);
}


#endif //WORKSHOP7_MOTORVEHICLE_H
