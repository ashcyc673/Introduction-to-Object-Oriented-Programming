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

#include "MotorVehicle.h"

namespace sdds
{
    MotorVehicle::MotorVehicle()
    {
        m_licPlate[0] = '\0';
        m_address[0] = '\0';
        m_year = 0;
    }

    MotorVehicle::MotorVehicle(const char plate[], int year)
    {
        if(plate == nullptr || year < 0)
        {
           *this = MotorVehicle();

        } else{

            strncpy(m_licPlate, plate,MAX_PLATE + 1);
            m_year = year;
            strcpy(m_address, "Factory");
        }
    }

    void MotorVehicle::moveTo(const char address[])
    {

        cout << right << "|" << setw(10) << m_licPlate << "| ";
        cout << right << "|" << setw(20) << m_address << " --->--- ";
        cout << left << setw(20) << address << "|" << endl;
        strcpy(m_address,address);
    }

    ostream& MotorVehicle::write(ostream& os = std::cout) const
    {
        os << "| " << m_year << " | " << m_licPlate << " | " << m_address;
        return os;
    }

    istream& MotorVehicle::read(istream& in = std::cin)
    {
        cout << "Built year: ";
        in >> m_year;
        in.clear();
        in.ignore(1000, '\n');
        cout << "License plate: ";
        in >> m_licPlate;
        in.clear();
        in.ignore(1000, '\n');
        cout << "Current location: ";
        in >> m_address;
        in.clear();
        in.ignore(1000, '\n');

        return in;
    }

    ostream& operator<<(ostream& ostr, const MotorVehicle& mo)
    {
        mo.write(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, MotorVehicle& mo)
    {
        mo.read(istr);
        return istr;
    }

    MotorVehicle::~MotorVehicle()
    {

    }

}
