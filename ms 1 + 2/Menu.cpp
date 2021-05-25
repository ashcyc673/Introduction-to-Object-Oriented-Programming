/* Citation and Sources... Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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
#include "Menu.h"
#include <cstring>

namespace sdds {
    MenuItem::MenuItem() {
        m_mItemName = nullptr;
    }

    MenuItem::MenuItem(const char *mItemName) {
        if (mItemName == nullptr) {
            m_mItemName = nullptr;
        } else {
            m_mItemName = new char[strlen(mItemName) + 1];
            strcpy(m_mItemName, mItemName);
        }
    }

    std::ostream &MenuItem::display(std::ostream &os) const {
        os << m_mItemName << std::endl;
        return os;
    }

    void MenuItem::setItemName(const char *mItemName) {
        if (mItemName == nullptr) {
            delete[] m_mItemName;
            m_mItemName = nullptr;
        } else {
            delete[] m_mItemName;
            m_mItemName = new char[strlen(mItemName) + 1];
            strcpy(m_mItemName, mItemName);
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_mItemName;
        m_mItemName = nullptr;
    }

    Menu::Menu() {
        m_title = nullptr;
        m_indentation = 0;
        m_trackNum = 0;
    }

    Menu::Menu(const char *title, int indentation) {
        if (title == nullptr) {
            *this = Menu();

        } else {
            m_indentation = indentation;
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            m_trackNum = 0;
        }
    }

    Menu &Menu::operator=(const Menu &copymenu) {
        if (!isEmpty()) {
            delete[] m_title;
            m_title = nullptr;
            m_trackNum = 0;
            m_indentation = 0;
        }
        if (this != &copymenu) {
            m_indentation = copymenu.m_indentation;
            m_trackNum = copymenu.m_trackNum;

            if (copymenu.m_title != nullptr) {
                m_title = new char[strlen(copymenu.m_title) + 1];
                strcpy(m_title, copymenu.m_title);

                for (int i = 0; i < m_trackNum; i++) {
                   // m_menuItems[i].setItemName(copymenu.m_menuItems[i].m_mItemName);
                    add(copymenu.m_menuItems[i].m_mItemName);
                }
            }
        }
        return *this;
    }

    Menu::Menu(const Menu &others) {
        if (others.m_title != nullptr) {
            m_indentation = others.m_indentation;
            m_trackNum = others.m_trackNum;
            m_title = new char[strlen(others.m_title) + 1];
            strcpy(m_title, others.m_title);

            for (int i = 0; i < m_trackNum; i++) {
                m_menuItems[i].setItemName(others.m_menuItems[i].m_mItemName);
            }
        } else {
            m_title = nullptr;
            m_trackNum = 0;
            m_indentation = 0;
        }

    }

    Menu::operator bool() const {
        return !isEmpty();
    }

    bool Menu::isEmpty() const {
        return (m_title == nullptr && m_indentation == 0 && m_trackNum == 0);
    }

    std::ostream &Menu::display(std::ostream &os) const {
        if (isEmpty()) {
            os << "Invalid Menu!" << std::endl;
        } else {
            addSpace();
            os << m_title << std::endl;
            if (m_trackNum == 0) {
                os << "No Items to display!" << std::endl;
            } else {

                for (int i = 0; i < m_trackNum; i++) {
                    addSpace();
                    os << i + 1 << "- ";
                    m_menuItems[i].display(os);
                }
                addSpace();
                os << "> ";
            }
        }
        return os;
    }

    Menu &Menu::operator=(const char *title) {
        if (!isEmpty()) {
            delete[] m_title;
        }
        if (title == nullptr) {
            m_title = nullptr;
            m_trackNum = 0;
            m_indentation = 0;

        } else {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
        return *this;
    }

    void Menu::add(const char *menuItems) {
        if (menuItems == nullptr) {
            m_indentation = 0;
            m_trackNum = 0;
            delete[] m_title;
            m_title = nullptr;
        } else {
            if (m_trackNum < MAX_NO_OF_ITEMS && !isEmpty()) {
                m_menuItems[m_trackNum].setItemName(menuItems);
                m_trackNum += 1;
            }
        }
    }

    Menu &Menu::operator<<(const char *menuItem) {
        add(menuItem);
        return *this;
    }

    int Menu::run() const {
        char userInput[255];
        int result = 0;

        bool state = false;
        display();
        if (m_trackNum != 0) {
            while (!state) {
                std::cin >> userInput;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                if (!isNumber(userInput)) {
                    std::cout << "Invalid Integer, try again: ";
                } else {
                    result = std::stoi(userInput);

                    if (result < 1 || result > m_trackNum) {
                        std::cout << "Invalid selection, try again: ";
                    } else {
                        state = true;
                    }
                }
            }
        }

        return result;
    }

    void Menu::display() const {
        display(std::cout);
    }

    Menu::operator int() const {
        int castInt = run();
        return castInt;
    }

    void Menu::addSpace() const {
        for (int i = 0; i < m_indentation; i++) {
            std::cout << "    ";
        }
    }

    Menu::~Menu() {
        delete[] m_title;
        m_title = nullptr;
    }

}
