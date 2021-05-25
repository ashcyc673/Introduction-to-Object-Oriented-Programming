

#ifndef MS3_MENU_H
#define MS3_MENU_H
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

#endif //MS3_MENU_H
