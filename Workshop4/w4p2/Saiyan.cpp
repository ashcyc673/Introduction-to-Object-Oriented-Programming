//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           06/18/2020
//==============================================
// Workshop:   4
// Part:      2
//==============================================
#include <iostream>
#include <cstring>
#include "Saiyan.h"
using namespace std;

namespace sdds
{
    Saiyan::Saiyan()
    {
        m_name = nullptr;
        m_dob = 0;
        m_power = 0;
        m_level = 0;
        m_super = false;
    }

    Saiyan::Saiyan(const char* name, int dob, int power)
    {

        if(name == nullptr ||name[0] == '\0' || dob > 2020  || power < 0)
        {
            m_name = nullptr;
            m_dob = 0;
            m_power = 0;
            m_super = false;
            m_level = 0;

        }
        else{
            m_name = new char[strlen(name)+1];
            strcpy(m_name,name);
            m_dob = dob;
            m_power = power;
            m_super = false;
            m_level = 0;

        }
    }
    void Saiyan::set(const char* name, int dob, int power, int level, bool super)
    {
            if(name == nullptr ||name[0] == '\0' || dob > 2020  || power < 0)
            {
                m_name = nullptr;
                m_dob = 0;
                m_power = 0;
                m_level = 0;

            }
            else{
                if(m_name)
                {
                    delete[] m_name;
                }
                m_name = new char[strlen(name) + 1];
                strcpy(m_name,name);
                m_dob = dob;
                m_power = power;
                m_super = super;
                m_level = level;

            }

    }

    bool Saiyan::isValid() const
    {
        bool state = false;
        if(m_name != nullptr && m_name[0] != '\0' && m_power > 0 && m_dob < 2020)
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
        }
        else
        {
            cout << m_name << endl;
            cout << "     DOB: " << m_dob << endl;
            cout << "   Power: " << m_power <<endl;
            cout << "   Super: " << (m_super ? "yes" : "no") << endl;
            if(m_super)
            {
                cout << "   Level: " << m_level << endl;
            }

        }
    }

    bool Saiyan::fight(Saiyan& other)
    {
        bool state = false;
        this->m_power = ((this->m_power/ 10) * this->m_level + this->m_power);
        other.m_power = ((other.m_power / 10) * other.m_level + other.m_power);

        if(m_power > other.m_power)
        {
            state = true;
        }
        return state;
    }

    Saiyan::~Saiyan() {
        delete [] m_name;
        m_name = nullptr;

    }
}

