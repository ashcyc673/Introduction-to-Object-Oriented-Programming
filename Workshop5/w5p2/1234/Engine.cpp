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

#include "Engine.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace sdds
{
    Engine::Engine()
    {
        m_size = 0;
        m_type[0] = '\0';

    }

    Engine::Engine(const char* type, double size)
    {
        strcpy(m_type,type);
        m_size = size;

    }

    double Engine::get() const
    {
        return m_size;
    }

    void Engine::display() const
    {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << m_size << " liters - " << m_type << endl;
    }




}

