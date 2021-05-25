//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           06/14/2020
//==============================================
// Workshop:   3
// Part:      2
//==============================================
#ifndef W3P1_TRAIN_H
#define W3P1_TRAIN_H
#include "Cargo.h"
#include <cstring>
#include <iostream>

namespace sdds
{
    const int MAX_NAME = 30;

    class Train {
        char m_name[MAX_NAME + 1];
        int m_id;
        Cargo* m_cargo;

    public:
        void initialize(const char* name, int id);
        bool isValid() const;
        void loadCargo(Cargo car);
        void unloadCargo();
        void display() const;
        bool swapCargo(Train& other);
        bool increaseCargo(double weight);
        bool decreaseCargo(double weight);
    };
}



#endif //W3P1_TRAIN_H
