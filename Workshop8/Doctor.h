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

#ifndef WORKSHOP8_DOCTOR_H
#define WORKSHOP8_DOCTOR_H


#include "Employee.h"

namespace sdds
{
    const int MaxDesc = 32;

    class Doctor : public Employee {

        char doctorType[MaxDesc + 1];
        bool specialist;

    public:

        Doctor(const char type[], double salary, int minHours, bool isSpecial = false);
        double getSalary(int workedHours);
        std::ostream& display(std::ostream& out);
        ~Doctor();
    };
}


#endif //WORKSHOP8_DOCTOR_H
