//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           06/18/2020
//==============================================
// Workshop:   4
// Part:      1
//==============================================

#ifndef W4P1_SAIYAN_H
#define W4P1_SAIYAN_H

namespace sdds
{
    const int MAX_DESC = 32;

    class Saiyan{

        char* m_name;
        int m_dob;
        int m_power;
        bool m_super;
        int m_level;

    public:
        Saiyan();
        Saiyan(const char* name, int dob, int power);
        void set(const char* name, int dob, int power, int level = 0, bool super = false);
        bool isValid() const;
        void display() const;
        bool fight(Saiyan& other);
        ~Saiyan();

    };



}


#endif //W4P1_SAIYAN_H
