/* Citation and Sources... Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.h
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

#ifndef MS3_MOTORCYCLE_H
#define MS3_MOTORCYCLE_H


#include "Vehicle.h"
#include "Utils.h"

namespace sdds
{
    class Motorcycle : public Vehicle {

        bool sidecar;

    public:

        Motorcycle();
        Motorcycle(const char* plate, const char* mkmd);
        Motorcycle& operator=(const Motorcycle& others) = delete;
        Motorcycle(const Motorcycle& others) = delete;
        std::istream& read(std::istream& istr) override;
        std::ostream& write(std::ostream& ostr) const override;
        ~Motorcycle() override ;

    };
}


#endif //MS3_MOTORCYCLE_H
