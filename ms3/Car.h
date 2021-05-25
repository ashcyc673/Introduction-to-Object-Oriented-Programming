/* Citation and Sources... Final Project Milestone 5
Module: Car
Filename: Car.h
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

#ifndef MS3_CAR_H
#define MS3_CAR_H

#include "Vehicle.h"
#include "Utils.h"

namespace sdds
{
    class Car : public Vehicle{

        bool carWash;

    public:

        Car();
        Car(const char* plate, const char* mkmd);
        Car& operator=(const Car& others) = delete;
        Car(const Car& others) = delete;
        std::istream& read(std::istream& istr) override;
        std::ostream& write(std::ostream& ostr) const override;
        ~Car() override;
        void withCarWash();
    };
}


#endif //MS3_CAR_H
