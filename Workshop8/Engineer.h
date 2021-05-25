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

#ifndef WORKSHOP8_ENGINEER_H
#define WORKSHOP8_ENGINEER_H


#include "Employee.h"

namespace sdds
{

    class Engineer : public Employee {

        int levelEnineer;

    public:

        Engineer(double salary, int level, int minHours = 30);
        double getSalary(int workedHours);
        std::ostream& display(std::ostream& out);
        ~Engineer();

    };
}


#endif //WORKSHOP8_ENGINEER_H
