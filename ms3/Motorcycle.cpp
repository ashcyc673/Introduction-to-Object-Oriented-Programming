//* Citation and Sources... Final Project Milestone 5
//Module: Motorcycle
//Filename: Motorcycle.cpp
//Version 1.0
//Author Chiao-Ya Chang
//Revision History
//-----------------------------------------------------------
//Date Reason
//2020/7/25 Preliminary release
//2020/7/25 Debugged DMA
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------*/

#include "Motorcycle.h"
using namespace std;

namespace sdds
{
    Motorcycle::Motorcycle() : Vehicle()
    {
        sidecar = false;
    }

    Motorcycle::Motorcycle(const char* plate, const char* mkmd) : Vehicle(plate, mkmd)
    {
        sidecar = false;
    }

    std::istream& Motorcycle::read(std::istream& istr)
    {
        char input[256];


        if(isCsv())
        {
            Vehicle::read(istr);
            istr.getline(input,255, '\n');
            if(input[0] == '1')
            {
                sidecar = true;

            } else if(input[0] == '0')
            {
                sidecar = false;

            } else
            {
                sidecar = false;
            }


        } else
        {
            cout << endl;
            cout << "Motorcycle information entry" << endl;
            Vehicle::read(istr);
            cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

            sidecar = getUserDecision();

        }
        return istr;
    }

    std::ostream& Motorcycle::write(std::ostream& ostr) const
    {
        if(isEmpty())
        {
            ostr << "Invalid Motorcycle Object" << endl;

        } else
        {
            if(isCsv())
            {
                ostr << "M,";
                Vehicle::write(ostr);
                if(sidecar)
                {
                    ostr << "1" << endl;
                }
                else
                {
                    ostr << "0" << endl;
                }

            } else
            {
                ostr << "Vehicle type: Motorcycle" << endl;
                Vehicle::write(ostr);
                if(sidecar)
                {
                    ostr << "With Sidecar"  << endl;
                }
            }
        }
        return ostr;
    }

    Motorcycle::~Motorcycle()
    {

    }
}