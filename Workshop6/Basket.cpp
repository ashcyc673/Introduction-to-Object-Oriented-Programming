//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           07/06/2020
//==============================================
// Workshop:   6
// Part:      1
//==============================================
#include <iostream>

using namespace std;

#include "Basket.h"

namespace sdds {
    Basket::Basket() {
        m_cnt = 0;
        m_price = 0;
        m_fruits = nullptr;
    }

    Basket::Basket(const Fruit *fruits, int cnt, double price) {
        if (fruits == nullptr || price < 0 || cnt < 0) {
            *this = Basket();
        } else {

            m_fruits = new Fruit[cnt];
            m_price = price;
            m_cnt = cnt;
            for (int i = 0; i < cnt; i++) {
                m_fruits[i] = fruits[i];
            }
        }
    }

    Basket::Basket(const Basket &copy)
    {
        if (copy.m_fruits == nullptr)
        {
            m_cnt = 0;
            m_price = 0;
            m_fruits = nullptr;
        } else {
            m_price = copy.m_price;
            m_cnt = copy.m_cnt;
            m_fruits = new Fruit[copy.m_cnt];
            for (int i = 0; i < copy.m_cnt; i++) {
                m_fruits[i] = copy.m_fruits[i];
            }
        }
    }

    Basket &Basket::operator=(const Basket &copy) {
       if(!isEmpty())
       {
           delete[] m_fruits;
           m_fruits = nullptr;
           m_price = 0;
           m_cnt = 0;
       }
        if (this != &copy) {
            m_price = copy.m_price;
            m_cnt = copy.m_cnt;
            if (copy.m_fruits != nullptr) {
                m_fruits = new Fruit[copy.m_cnt];
                for (int i = 0; i < copy.m_cnt; i++) {
                    m_fruits[i] = copy.m_fruits[i];
                }
            } else {
                m_fruits = nullptr;
            }
        }
        return *this;

    }

    void Basket::setPrice(double price) {
        if (m_price < 0) {
            m_price = 0;
        } else {
            m_price = price;
        }
    }

    bool Basket::isEmpty() const {
        return (m_fruits == nullptr && m_cnt == 0 && m_price == 0);
    }

    Basket::operator bool() const {
        return !isEmpty();
    }

    Basket &Basket::operator+=(Fruit fruit) {

        if (fruit.m_name[0] != '\0') {
            Fruit *temp = new Fruit[m_cnt];
            for (int i = 0; i < m_cnt; i++) {
                temp[i] = m_fruits[i];
            }
            delete[] m_fruits;
            m_fruits = new Fruit[m_cnt + 1];
            for (int i = 0; i < m_cnt; i++) {
                m_fruits[i] = temp[i];
            }
            m_fruits[m_cnt] = fruit;
            m_cnt++;
            delete [] temp;
        }
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const Basket &bk)
    {
        if (!bk)
        {
            os << "The basket is empty!" << endl;
        } else{
            os << "Basket Content:" << std::endl;
            for (int i = 0; i < bk.m_cnt; i++)
            {
                os.setf(ios::fixed);
                os.precision(2);
                os.width(10);
                os << bk.m_fruits[i].m_name << ": " << bk.m_fruits[i].m_qty << "kg" << endl;
                os.unsetf(ios::fixed);
            }
            os.setf(ios::fixed);
            os.precision(2);
            os << "Price: " << bk.m_price << endl;
            os.unsetf(ios::fixed);
        }

        return os;
    }

    Basket::~Basket() {
        delete[] m_fruits;
        m_fruits = nullptr;
    }
}
