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

#include "Ship.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds
{

    Ship::Ship()
    {
        m_type = nullptr;
        m_engines = nullptr;
        m_engCnt = 0;
    }

    Ship::Ship(const char type[], Engine* engines, int engCnt)
    {
        if(type[0] == '\0' || engines == nullptr || engCnt < 0 || strlen(type) > TYPE_MAX_SIZE)
        {
            *this = Ship();

        } else{
            m_type = new char[strlen(type) + 1];
            strcpy(m_type,type);
            m_engCnt = engCnt;
            m_engines = new Engine[m_engCnt];
            for(int i = 0; i < engCnt; i++)
            {
                m_engines[i] = engines[i];
            }
        }

    }

    Ship::operator bool() const
    {
        bool state = false;
        if(m_type != nullptr && m_engCnt != 0 )
        {
            state = true;
        }
        return state;
    }

    Ship& Ship::operator+=(Engine engine)
    {
        if(m_type == nullptr || m_engCnt == 0)
        {
            cout << "The object is not valid! Engine cannot be added!" << endl;
        } else
        {
            Engine* tmpEngine = new Engine[m_engCnt + 1];
            for (int i = 0; i < m_engCnt; ++i) {
                tmpEngine[i] = m_engines[i];
            }
            tmpEngine[m_engCnt] = engine;
            m_engCnt = m_engCnt + 1;
            delete[] m_engines;
            m_engines = new Engine[m_engCnt];
            for (int i = 0; i < m_engCnt; ++i) {
                m_engines[i] = tmpEngine[i];
            }
            delete[] tmpEngine;
        }

        return *this;
    }

    double Ship::calTotalPower() const
    {
        double result = 0;
        for(int i = 0; i < m_engCnt ; i++)
        {
            result += m_engines[i].get() * 5;
        }
        return result;
    }

    bool Ship::operator<(double power) const
    {
        bool state = false;
        if(calTotalPower() < power)
        {
            state = true;
        }
        return state;

    }

    void Ship::display() const
    {
        if(m_type == nullptr || m_engCnt == 0)
        {
            cout << "No available data" << endl;
        }
        else{
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << m_type << " - ";
            cout.width(6);
            cout << calTotalPower() << endl;

            for(int i = 0; i < m_engCnt; i++)
            {
                m_engines[i].display();

            }
            cout.precision(3);
        }
    }

    bool operator<(double power, const Ship& theShip)
    {
        bool state = false;

        if (power < theShip.calTotalPower())
        {
            state = true;
        }
        return state;

    }

    Ship::~Ship() {
        delete[] m_engines;
        delete[] m_type;

    }
}
