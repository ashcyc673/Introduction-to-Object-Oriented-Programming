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

#include "Ship.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds
{

    Ship::Ship()
    {
        m_type[0] = '\0';
        m_engCnt = 0;
    }

    Ship::Ship(const char type[], Engine* engines, int engCnt)
    {
      if(type[0] == '\0' || engines == nullptr || engCnt < 0 || strlen(type) > TYPE_MAX_SIZE)
      {
         *this = Ship();

      } else{
          strcpy(m_type,type);
          for(int i = 0; i < engCnt; i++)
          {
              m_engines[i] = engines[i];
          }
          m_engCnt = engCnt;
      }

    }

    Ship::operator bool() const
    {
        bool state = false;
        if(m_type[0] != '\0' && m_engCnt != 0 )
        {
            state = true;
        }
        return state;
    }

    Ship& Ship::operator+=(Engine engine)
    {
        if(m_type[0] == '\0' || m_engCnt == 0)
        {
            cout << "The object is not valid! Engine cannot be added!" << endl;
        } else
        {
            m_engines[m_engCnt ++] = engine;
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
        if(m_type[0] == '\0' || m_engCnt == 0)
        {
            cout << "No available data" << endl;
        }
        else{
            cout << m_type << " - " << calTotalPower() << endl;

            for(int i = 0; i < m_engCnt; i++)
            {
                m_engines[i].display();
            }
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




}
