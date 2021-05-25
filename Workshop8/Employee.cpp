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

#include "Employee.h"

namespace sdds
{

    Employee::Employee(double salary, int minHours) : minHourWork(minHours)
    {
        if(salary < 0 || minHours < 0)
        {
           hourlySalary = 0;
        }
        else{

            hourlySalary = salary;

        }
    }

    int Employee::getMinHours() const
    {
        return minHourWork;
    }

    double Employee::getHourlySal() const
    {
        return hourlySalary;
    }

    std::ostream& operator<<(std::ostream& ostr, const Employee&)
    {
        return ostr;
    }

    Employee::~Employee()
    {

    }


}