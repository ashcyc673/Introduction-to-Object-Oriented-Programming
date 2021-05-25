/* Citation and Sources... Final Project Milestone 6
Module: Parking
Filename: Parking.h
Version 1.0
Author Chiao-Ya Chang
Revision History
-----------------------------------------------------------
Date Reason
2020/7/30 Preliminary release
2020/7/30 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef MS3_PARKING_H
#define MS3_PARKING_H

#include <fstream>
#include "Menu.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"

using namespace std;

namespace sdds
{
    const int MAX_PARKING_SPOT = 100;

    class Parking {
        char* m_filename;
       // Menu* m_parkingMenu;
       Menu m_parkingMenu;
       // Menu* m_vehiSeleMenu;
       Menu m_vehiSeleMenu;

        int numSpot;
        Vehicle* parkSpot[MAX_PARKING_SPOT];
        int numParkedVehicle;

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
        Parking(const char* filename, int noOfSpots=0);
        ~Parking();
        Parking(const Parking& others) = delete;
        int run();

    };
}

#endif //MS3_PARKING_H
