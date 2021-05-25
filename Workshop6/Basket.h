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

#ifndef WS6_BASKET_H
#define WS6_BASKET_H

namespace sdds
{   const int MAX = 30;
    struct Fruit
    {
        char m_name[MAX + 1];
        double m_qty;
    };

    class Basket
    {
        Fruit* m_fruits;
        int m_cnt;
        double m_price;
    public:
        Basket();
        Basket(const Fruit* fruits, int cnt, double price);
        Basket(const Basket& copy);
        Basket& operator=(const Basket& copy);
        ~Basket();
        void setPrice(double price);
        Basket& operator+=(Fruit fruit);
        bool isEmpty() const;
        friend std::ostream& operator<<(std::ostream& os, const Basket& bk);
        operator bool() const;
    };
}



#endif //WS6_BASKET_H
