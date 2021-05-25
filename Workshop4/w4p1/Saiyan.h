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

#ifndef W4P1_SAIYAN_H
#define W4P1_SAIYAN_H

namespace sdds
{
    const int MAX_DESC = 32;
    class Saiyan{

        char m_name[MAX_DESC + 1];
        int m_dob;
        int m_power;
        bool m_super;

    public:
        Saiyan();
        Saiyan(const char* name, int dob, int power);
        void set(const char* name, int dob, int power, bool super = false);
        bool isValid() const;
        void display() const;
        bool fight(const Saiyan& other) const;
        ~Saiyan();

    };

}


#endif //W4P1_SAIYAN_H
