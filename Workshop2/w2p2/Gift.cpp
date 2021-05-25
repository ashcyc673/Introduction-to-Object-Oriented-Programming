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

#include "Gift.h"
#include <iostream>
#include <cstring>
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

       if (theGift.m_wrapLayers == 0)
       {
            cout << "Unwrapped!" << endl;
       } else
       {
           cout << "Wrap Layers: " << theGift.m_wrapLayers << endl;
           for (int counter = 0; counter < theGift.m_wrapLayers; counter++)
           {
               cout << "Wrap #" << counter + 1 << " -> " << theGift.m_wrap[counter].m_pattern << endl;
           }
       }
    }

    bool wrap(Gift& theGift)
    {
        if(theGift.m_wrapLayers != 0) {

            cout << "Gift is already wrapped!" << endl;
            return false;

        } else{

            cout << "Wrapping gifts..." << endl;

        }

        bool state = false;

        while(!state)
        {

            cout << "Enter the number of wrapping layers for the Gift: ";
            cin >> theGift.m_wrapLayers;

            if(theGift.m_wrapLayers < 1)
            {
                cout << "Layers at minimum must be 1, try again." << endl;
            }
            else{
                state = true;
            }
        }

        theGift.m_wrap = nullptr;
        theGift.m_wrap = new Wrapping[theGift.m_wrapLayers];
        for ( int counter = 0 ; counter < theGift.m_wrapLayers ; counter++)
        {
            char userInput[256];
            cout << "Enter wrapping pattern #" << counter + 1 << ": ";
            cin >> userInput;
            cin.clear();
            cin.ignore(1000,'\n');

            theGift.m_wrap[counter].m_pattern = new char[strlen(userInput) + 1] ;
            strcpy(theGift.m_wrap[counter].m_pattern, userInput);
        }
        return true;

    }

    bool unwrap(Gift& theGift)
    {
        if (theGift.m_wrapLayers == 0)
        {
            cout << "Gift isn't wrapped! Cannot unwrap." << endl;
            return false;
        } else
        {
            cout << "Gift being unwrapped." << endl;
            for(int i=0; i < theGift.m_wrapLayers; i++)
            {
                delete[] theGift.m_wrap[i].m_pattern;
                theGift.m_wrap[i].m_pattern = nullptr;
            }
            delete[] theGift.m_wrap;
            theGift.m_wrap = nullptr;
            theGift.m_wrapLayers = 0;

            return true;
        }

    }

    void gifting(Gift& theGift)
    {
        cout << "Preparing a gift..." << endl;
        gifting(theGift.m_description);
        gifting(theGift.m_price);
        gifting((theGift.m_units));
        wrap(theGift);
    }

}
