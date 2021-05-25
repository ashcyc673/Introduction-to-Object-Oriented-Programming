/* Citation and Sources... Final Project Milestone 5
Module: Car
Filename: Car.cpp
Version 1.0
Author Chiao-Ya Chang
Revision History
-----------------------------------------------------------
Date Reason
2020/7/25 Preliminary release
2020/7/25 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Car.h"
using namespace std;

namespace sdds
{
    Car::Car() : Vehicle()
    {
        carWash = false;
    }

    Car::Car(const char* plate, const char* mkmd) : Vehicle(plate, mkmd)
    {
        carWash = false;
    }
    std::istream& Car::read(std::istream& istr)
    {
        char input[256];

        if(isCsv())
        {
            Vehicle::read(istr);
            istr.getline(input,255, '\n');
            if(input[0] == '1')
            {
                carWash = true;

            } else if(input[0] == '0')
            {
                carWash = false;

            } else
            {
                carWash = false;
            }


        } else
        {
            cout << endl;
            cout << "Car information entry" << endl;
            Vehicle::read(istr);
            cout << "Carwash while parked? (Y)es/(N)o: ";

            carWash = getUserDecision();

        }
        return istr;
    }

    std::ostream& Car::write(std::ostream& ostr) const
    {
        if(isEmpty())
        {
            ostr << "Invalid Car Object" << endl;

        } else
        {
            if(isCsv())
            {
                ostr << "C,";
                Vehicle::write(ostr);
                if(carWash)
                {
                    ostr << "1" << endl;
                }
                else
                {
                    ostr << "0" << endl;
                }

            } else
            {
                ostr << "Vehicle type: Car" << endl;
                Vehicle::write(ostr);
                if(carWash)
                {
                    ostr << "With Carwash" << endl;

                }
                else
                {
                    ostr << "Without Carwash" << endl;
                }
            }
        }

       return ostr;
    }

    Car::~Car()
    {

    }
}
