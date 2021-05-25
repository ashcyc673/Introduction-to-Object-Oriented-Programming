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

#ifndef W3P1_CARGO_H
#define W3P1_CARGO_H


namespace sdds
{
    const char MAX_DESC = 20;
    struct Cargo
    {
       char m_desc[MAX_DESC + 1];
       float m_price;
    };
}


#endif //W3P1_CARGO_H
