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

#include "Train.h"
#include "Cargo.h"

using namespace std;

namespace sdds
{
    void Train::initialize(const char* name, int id)
    {

        if(name == nullptr || name[0] == '\0'|| id < 0)
        {
            m_cargo = nullptr;
            m_name[0] = '\0';
            m_id = 0;
        } else
        {
            strncpy(m_name,name,MAX_NAME);
            m_id = id;
            m_cargo = nullptr;
        }


    }

    bool Train::isValid() const
    {
        bool state = true;
        if (m_name[0] == '\0' || m_id <= 0 )
        {
            state = false;
        }
        return state;
    }

    void Train::loadCargo(Cargo car)
    {
        if(m_cargo != nullptr)
        {
            unloadCargo();
        }
        m_cargo = new Cargo();
        m_cargo->setDesc((car.getDesc()));
        m_cargo->setWeight(car.getWeight());
    }

    void Train::unloadCargo()
    {
        delete m_cargo;
        m_cargo = nullptr;
    }

    void Train::display() const
    {
        if(!isValid())
        {
            //if the train is an invalid object
            cout << "***Train Summary***" << endl;
            cout << "This is an invalid train." << endl;
        }


        else if (m_cargo == nullptr)
        {
            // if the train carries no cargo, print
            cout << "***Train Summary***" << endl;
            cout << "    Name: " << m_name << endl;
            cout << "      ID: " << m_id <<endl;
            cout << "No cargo on this train." << endl;
        }
        else{
            // otherwise, print
            cout << "***Train Summary***" << endl;
            cout << "    Name: " << m_name << endl;
            cout << "      ID: " << m_id << endl;

            cout << "   Cargo: " << m_cargo->getDesc() << endl;
            cout.setf(ios::fixed); // round the number use setf before precistion.
            cout.precision(2);
            cout << "  Weight: " << m_cargo->getWeight() << endl;
            cout.unsetf(ios::fixed);

        }



    }
    bool Train::swapCargo(Train& other)
    {
        bool state = false;
        Cargo * t_cargo = nullptr;

        if(m_cargo != nullptr && other.m_cargo != nullptr)
        {
            t_cargo = other.m_cargo;
            other.m_cargo = m_cargo;
            m_cargo = t_cargo;
            state = true;
        }
        return state;
    }

    bool Train::increaseCargo(double weight)
    {
        bool state = false;
        if(m_cargo != nullptr)
        {
            double c_weight = m_cargo->getWeight();
            double n_weight;

            if(c_weight < MAX_WEIGHT)
            {
                n_weight = c_weight + weight;
                if (n_weight >= MIN_WEIGHT && n_weight <= MAX_WEIGHT)
                {
                    m_cargo->setWeight(n_weight);
                }
                else
                {
                    m_cargo->setWeight((MAX_WEIGHT));

                }
                cout.setf(ios::fixed);
                cout.precision(3);
                state = true;
            }
        }
       return state;
    }


    bool Train::decreaseCargo(double weight)
    {
        bool state = false;
        if(m_cargo != nullptr)
        {
            double c_weight = m_cargo->getWeight();
            double n_weight;
            if (c_weight != MIN_WEIGHT)
            {
                n_weight = c_weight - weight;
                if(n_weight > MIN_WEIGHT)
                {
                    m_cargo->setWeight(n_weight);
                } else
                    {
                        m_cargo->setWeight(MIN_WEIGHT);
                    }
                state = true;
            }

            cout.setf(ios::fixed);
            cout.precision(4);

        }
        return state;
    }
}
