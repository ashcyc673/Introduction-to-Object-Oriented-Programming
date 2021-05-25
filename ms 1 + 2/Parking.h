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

#ifndef MS1_PARKING_H
#define MS1_PARKING_H
#include "Menu.h"
using namespace std;

namespace sdds
{
    class Parking {
        char* m_filename;
        Menu* m_parkingMenu;
        Menu* m_vehiSeleMenu;

        bool isEmpty() const;
        void parkStatus();
        void parkVehicle();
        void returnVehicle();
        void listParkedVehicle();
        bool closeParking();
        bool exitParkingApp();
        bool loadDataFile();
        void saveDataFile();
        void pkMenu();
        void vcMenu();


    public:
        Parking();
        Parking(const char* filename);
        ~Parking();
        Parking(const Parking& others) = delete;
        int run();


    };
}



#endif //MS1_PARKING_H
