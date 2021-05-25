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

#include "Truck.h"

namespace sdds
{
    Truck::Truck() : MotorVehicle()
    {
        m_capacity = 0;
        m_currentCargo = 0;
    }

    Truck::Truck(const char plate[], int year, double capacity, const char address[]) : MotorVehicle(plate, year)
    {
        if(capacity < 0)
        {
            *this = Truck();

        } else
        {
            m_capacity = capacity;
            m_currentCargo = 0;
            MotorVehicle::moveTo(address);
        }
    }

    bool Truck::addCargo(double cargo)
    {
        bool state = false;

        if(m_currentCargo < m_capacity)
        {
            m_currentCargo += cargo;
            state = true;
            if(m_currentCargo > m_capacity)
            {
                m_currentCargo = m_capacity;
            }
        }
        return state;
    }

    bool Truck::unloadCargo()
    {
        bool state = false;
        if(m_currentCargo != 0)
        {
            m_currentCargo = 0;
            state = true;
        }
        return state;
    }

    ostream& Truck::write(ostream& os = std::cout) const
    {
        MotorVehicle::write(os);
        os << " | " << m_currentCargo << "/" << m_capacity;

        return os;
    }

    istream& Truck::read(istream& in = std::cin)
    {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> m_capacity;
        in.clear();
        in.ignore(1000, '\n');
        cout << "Cargo: ";
        in >> m_currentCargo;
        in.clear();
        in.ignore(1000, '\n');

        return in;
    }

    ostream& operator<<(ostream& ostr, const Truck& tk)
    {
        tk.write(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, Truck& tk)
    {
        tk.read(istr);
        return istr;
    }

    Truck::~Truck()
    {

    }

}
