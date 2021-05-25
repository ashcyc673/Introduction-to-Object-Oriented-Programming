//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           06/09/2020
//==============================================
// Workshop:   3
// Part:      1
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
        }
        else
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
        strcpy(m_cargo->m_desc, car.m_desc);
        m_cargo->m_price = car.m_price;

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
            cout << "Name: " << m_name << endl;
            cout << "ID: " << m_id <<endl;
            cout << "No cargo on this train." << endl;
        }
        else{
            // otherwise, print
            cout << "***Train Summary***" << endl;
            cout << "Name: " << m_name << endl;
            cout << "ID: " << m_id << endl;
            cout << "Cargo: " << m_cargo->m_desc << endl;
           // cout.setf(ios::fixed); // round the number use setf before precistion.
           //cout.precision(2);
            cout << "Weight: " << m_cargo->m_price << endl;

        }



    }
}
