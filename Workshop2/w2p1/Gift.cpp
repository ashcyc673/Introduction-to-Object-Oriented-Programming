//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           06/02/2020
//==============================================
// Workshop:     2
// Part:      1
//==============================================

#include "Gift.h"
#include <iostream>
using namespace std;

namespace sdds
{
    void gifting(char* desc)
    {
        cout << "Enter gift description: ";
        cin.width(MAX_DESC + 1);
        cin >> desc;
    }

    void gifting(double& price)
    {
            bool state = false;
            while (!state) {

                cout << "Enter gift price: ";
                cin >> price;

                //invalid message
                if (price < 0 || price >= MAX_PRICE) {
                    cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
                } else
                {
                    state = true;
                }
            }
    }



    void gifting(int& units)
    {
        bool state = false;
        while (!state)
        {

        cout << "Enter gift units: ";
        cin >> units;

        //invalid message
        if(units <= 0)
        {
            cout << "Gift units must be at least 1" << endl;
        }else
        {
            state = true;
        }
        }
    }



    void display(const Gift& theGift)

    {
        cout << "Gift Details:" << endl;
        cout << " Description: " << theGift.m_description << endl;
        cout << "       Price: " << theGift.m_price << endl;
        cout << "       Units: " << theGift.m_units << endl;
        cout << endl;

    }

}
