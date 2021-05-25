//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           07/19/2020
//==============================================
// Workshop:   8
// Part:      1
//==============================================

#include "Doctor.h"

using namespace std;

namespace sdds
{


    Doctor::Doctor(const char* type, double salary, int minHours, bool isSpecial) : Employee(salary,minHours)
    {
        if(type[0] == '\0' || salary < 0 || minHours < 0)
        {
            doctorType[0] = '\0';

        } else{

            strncpy(doctorType,type,MaxDesc);
            specialist = isSpecial;
        }

    }

    double Doctor::getSalary(int workedHours)
    {
        int underT = workedHours * (int)getHourlySal();
        int overT = (getMinHours() * (int)getHourlySal()) + (workedHours - getMinHours()) * (int)getHourlySal() * 1.5;
        int sum = 0;

        if(workedHours < getMinHours())
        {
           sum += underT;
           if(specialist)
           {
               sum += 2000;
           }
        }
        if(workedHours > getMinHours())
        {
           sum += overT;
           if(specialist)
           {
               sum += 2000;
           }
        }
        return sum;
    }

    std::ostream& Doctor::display(std::ostream& out = std::cout)
    {
        cout << "Doctor" << endl;
        if(!specialist)
        {
            out << right << setw(16) << "Type: " << doctorType << endl;

        } else{

            out << right << setw(16) << "Type: " << doctorType << " (specialist)"<< endl;
        }

        out << right << setw(16) << "Pay Rate: " << getHourlySal() << endl;
        out << right << setw(16) << "Min Hours: " << getMinHours() << endl;

        return out;
    }

    Doctor::~Doctor()
    {

    }
}