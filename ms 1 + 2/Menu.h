/* Citation and Sources... Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author Chiao-Ya Chang
Revision History
-----------------------------------------------------------
Date Reason
2020/7/9 Preliminary release
2020/7/9 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef MS1_MENU_H
#define MS1_MENU_H
#include <cstring>
#include <iostream>
#include "Utils.h"
namespace sdds
{
    const int MAX_NO_OF_ITEMS = 10;
    class MenuItem
    {
        friend class Menu;
        MenuItem();
        char* m_mItemName;
        MenuItem(const char* mItemName);
        std::ostream&  display(std::ostream& os) const;
        MenuItem& operator=(const MenuItem& others) = delete;
        MenuItem(const MenuItem& others) = delete;
        void setItemName(const char* mItemName);
        ~MenuItem();
    };

    class Menu
    {
        char* m_title;
        MenuItem m_menuItems[MAX_NO_OF_ITEMS];
        int m_indentation;
        int m_trackNum;

    public:
        Menu();
        Menu(const char* title, int indentation = 0);
        Menu& operator=(const Menu& copymenu);
        Menu(const Menu& others);
        operator bool() const;
        bool isEmpty()const;
        std::ostream& display(std::ostream& os) const;
        void display()const;
        Menu& operator=(const char* title);
        void add(const char* menuItems);
        Menu& operator<<(const char* menuItem);
        int run() const;
        operator int() const;
        void addSpace() const;
        ~Menu();
    };


}



#endif //MS1_MENU_H
