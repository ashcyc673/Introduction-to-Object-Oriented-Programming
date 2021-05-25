//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           07/15/2020
//==============================================
// Workshop:   8
// Part:      1
//==============================================

#include "Engineer.h"
using namespace std;

namespace sdds
{

    Engineer::Engineer(double salary, int level , int minHours) : Employee(salary,minHours)
    {
        if(level < 0)
        {
            levelEnineer = 0;

        } else{

            levelEnineer = level;

        }
    }

    double Engineer::getSalary(int workedHours)
    {
        int underT = workedHours * (int)getHourlySal()+ (levelEnineer * 40);
        int overT = (workedHours * (int)getHourlySal()) + (levelEnineer * 40);
        int sum = 0;

        if(workedHours < 30)
        {
            sum += underT * 0.8;
        }
        if(workedHours > 30)
        {
            sum += overT;
        }
        return sum;
    }

    std::ostream& Engineer::display(std::ostream& out = std::cout)
    {
        out << "Engineer" << endl;
        out << right << setw(20) << "Level: " << levelEnineer << endl;
        out << right << setw(20) << "Pay Rate: " << getHourlySal() << endl;
        out << right << setw(20) << "Min Hours: " << getMinHours() << endl;

        return out;
    }

    Engineer::~Engineer()
    {

    }

}