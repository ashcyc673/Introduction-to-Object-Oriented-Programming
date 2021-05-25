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
#include "Cargo.h"
#include <cstring>

namespace sdds
{

  void Cargo::initialize(const char* desc, double weight)
    {
        if( desc[0] == '\0' || weight == 0 || desc == nullptr)
        {
            m_desc[0] = '\0';
            m_weight = 0;
        } else
            {
                strncpy(m_desc,desc,MAX_DESC);
                m_weight = weight;
            }
    }
   const char*Cargo::getDesc() const
    {
        return m_desc;
    }
    double Cargo::getWeight() const
    {
        return m_weight;
    }
    void Cargo::setDesc(const char* description)
    {
        if(description != nullptr && strlen(description) != 0)
        {
            strncpy(m_desc,description,MAX_DESC);
        }
    }
    void Cargo::setWeight(double weight)
    {
        if (weight > MAX_WEIGHT || weight < MIN_WEIGHT) {
            m_weight = MIN_WEIGHT;
        }
        else {
            m_weight = weight;
        }


    }


}
