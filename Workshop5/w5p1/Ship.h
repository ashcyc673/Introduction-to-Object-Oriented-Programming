//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           06/21/2020
//==============================================
// Workshop:   5
// Part:      1
//==============================================

#ifndef W5P1_SHIP_H
#define W5P1_SHIP_H

#include "Engine.h"

namespace sdds
{
    const double MIN_STD_POWER = 90.111;
    const double MAX_STD_POWER = 99.999;

    class Ship {

        char m_type[TYPE_MAX_SIZE + 1];
        Engine m_engines[10];
        int m_engCnt;
        double calTotalPower() const;


    public:
        Ship();
        Ship(const char type[], Engine* engines, int engCnt);
        explicit operator bool() const;
        Ship& operator+=(Engine engine);
        bool operator<(double power) const;
        void display() const;
        friend bool operator<(double power, const Ship& theShip);

    };


}

#endif //W5P1_SHIP_H
