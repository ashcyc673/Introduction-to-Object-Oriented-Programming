//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           06/15/2020
//==============================================
// Workshop:   4
// Part:      1
//==============================================
#include <iostream>
#include <cstring>
#include "Saiyan.h"
using namespace std;

namespace sdds
{
    Saiyan::Saiyan()
    {
        m_name[0] = '\0';
        m_dob = 0;
        m_power = 0;
    }
    Saiyan::Saiyan(const char* name, int dob, int power)
    {
        set(name, dob, power);
    }
    void Saiyan::set(const char* name, int dob, int power, bool super)
    {
        if(name == nullptr ||name[0] == '\0' || dob >= 2020  || power <= 0)
        {
            m_name[0] = '\0';
            m_dob = 0;
            m_power = 0;
        }
        else{
                strncpy(m_name,name,MAX_DESC);
                m_dob = dob;
                m_power = power;
                m_super = super;
            }
    }
    bool Saiyan::isValid() const
    {
        bool state = false;
        if(m_name != nullptr && m_name[0] != '\0' && m_power >= 0 && m_dob <= 2020)
        {
            state = true;
        }
        return state;
    }
    void Saiyan::display() const
    {
        if(!isValid())
        {
            cout << "Invalid Saiyan!" << endl;
        } else
        {
            cout << m_name << endl;
            cout << "DOB: " << m_dob << endl;
            cout << "Power: " << m_power <<endl;
            cout << "Super: " << (m_super ? "yes" : "no") << endl;
        }
    }
    bool Saiyan::fight(const Saiyan& other) const
    {
        bool state = false;
        if(m_power > other.m_power)
        {
            state = true;
        }
        return state;
    }

    Saiyan::~Saiyan() {

    }
}
