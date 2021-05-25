//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           06/28/2020
//==============================================
// Workshop:   5
// Part:      2
//==============================================

#ifndef W5P2_SHIP_H
#define W5P2_SHIP_H

#include "Engine.h"

namespace sdds
{
    const double MIN_STD_POWER = 90.111;
    const double MAX_STD_POWER = 99.999;

    class Ship {

        char* m_type;
        Engine* m_engines;
        int m_engCnt;
        double calTotalPower() const;


    public:
        Ship();
        Ship(const char type[], Engine* engines, int engCnt);
        ~Ship();
        explicit operator bool() const;
        Ship& operator+=(Engine engine);
        bool operator<(double power) const;
        void display() const;
        friend bool operator<(double power, const Ship& theShip);

    };


}

#endif //W5P1_SHIP_H
