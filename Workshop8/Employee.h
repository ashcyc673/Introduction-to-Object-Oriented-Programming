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

#ifndef WORKSHOP8_EMPLOYEE_H
#define WORKSHOP8_EMPLOYEE_H
#include <iostream>
#include <cstring>
#include <iomanip>

namespace sdds
{
    class Employee {

        const int minHourWork;
        double hourlySalary;

    protected:

        int getMinHours() const;
        double getHourlySal() const;
       

    public:

        Employee(double salary, int minHours);
        virtual double getSalary(int workedHours) = 0;
        virtual std::ostream& display(std::ostream& out = std::cout) = 0;
        virtual ~Employee();

    };
    std::ostream& operator<<(std::ostream& ostr, const Employee&);
}


#endif //WORKSHOP8_EMPLOYEE_H
