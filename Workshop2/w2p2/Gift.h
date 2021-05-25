//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           06/07/2020
//==============================================
// Workshop:     2
// Part:      2
//==============================================

#ifndef WS2P1_GIFT_H
#define WS2P1_GIFT_H


namespace sdds {

    const int MAX_DESC = 15;
    const float MAX_PRICE = 999.999;
    const  int MAX_WRAP = 20;

    struct Wrapping
    {
        char*  m_pattern;
    };

    struct Gift
    {
        char m_description[MAX_DESC + 1];
        double m_price;
        int m_units;
        Wrapping*  m_wrap;
        int m_wrapLayers;
    };

    void gifting(char* desc);
    void gifting(double& price);
    void gifting(int& units);
    bool wrap(Gift& theGift);
    bool unwrap(Gift& theGift);
    void gifting(Gift& theGift);

    void display(const Gift& theGift);

}


#endif //WS2P1_GIFT_H
