/* Citation and Sources... Final Project Milestone 4
Module: Vehicle
Filename: Vehicle.h
Version 1.0
Author Chiao-Ya Chang
Revision History
-----------------------------------------------------------
Date Reason
2020/7/24 Preliminary release
2020/7/24 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef MS3_VEHICLE_H
#define MS3_VEHICLE_H

#include "ReadWritable.h"
#include <iostream>
#include <cstring>

namespace sdds
{
    const int MAX_PLATE = 8;
    class Vehicle : public ReadWritable {
        char* licensePlate;
        char* makeNmodel;
        int parkingSpotNum;

    protected:
        void setEmpty();
        bool isEmpty() const;
        char* getLicensePlate() const;
        char* getMakeModel() const;
        void setMakeModel(char* mkmd);
    public:
        Vehicle();
        Vehicle(const char* plate, const char* mkmd);
        Vehicle& operator=(const Vehicle& others) = delete;
        Vehicle(const Vehicle& others) = delete;
        ~Vehicle();
        int getParkingSpot() const;
        void setParkingSpot(int spot);
        friend bool operator==(const Vehicle& plate1, const Vehicle& plate2);
        friend bool operator==(const Vehicle& vehicle, const char* plateValue);

        std::istream& read(std::istream& istr) override;
        std::ostream& write(std::ostream& ostr) const override;

    };
    bool isIdentical(const char* firstString, const char* secondString);


}

#endif //MS3_VEHICLE_H
