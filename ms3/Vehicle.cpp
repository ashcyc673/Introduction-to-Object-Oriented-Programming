/* Citation and Sources... Final Project Milestone 4
Module: Vehicle
Filename: Vehicle.cpp
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
#include "Vehicle.h"

using namespace std;

namespace sdds
{
    Vehicle::Vehicle()
    {
        licensePlate = nullptr;
        makeNmodel = nullptr;
        parkingSpotNum = 0;
    }

    void Vehicle::setEmpty()
    {
        delete[] licensePlate;
        delete[] makeNmodel;

        licensePlate = nullptr;
        makeNmodel = nullptr;
        parkingSpotNum = 0;

    }

    bool Vehicle::isEmpty() const
    {
        return (licensePlate == nullptr || makeNmodel == nullptr || parkingSpotNum < 0);
    }

    char *Vehicle::getLicensePlate() const
    {
        return licensePlate;
    }

    char *Vehicle::getMakeModel() const
    {
        return makeNmodel;
    }

    void Vehicle::setMakeModel(char *mkmd)
    {
        if (mkmd == nullptr)
        {
            delete[] makeNmodel;
            makeNmodel = nullptr;
        } else {
            delete[] makeNmodel;
            makeNmodel = new char[strlen(mkmd) + 1];
            strcpy(makeNmodel, mkmd);

        }

    }

    Vehicle::Vehicle(const char *plate, const char *mkmd)
    {
        if (plate == nullptr || mkmd == nullptr || plate[0] == '\0' || mkmd[0] == '\0' || strlen(plate) > 8 || strlen(mkmd) < 2)
        {
            licensePlate = nullptr;
            makeNmodel = nullptr;
        } else {
            licensePlate = new char[strlen(plate) + 1];
            strcpy(licensePlate, plate);
            makeNmodel = new char[strlen(mkmd) + 1];
            strcpy(makeNmodel, mkmd);
            int i = 0;
            while (licensePlate[i])
            {
                licensePlate[i] = toupper(licensePlate[i]);
                ++i;
            }
        }
        parkingSpotNum = 0;
    }

    int Vehicle::getParkingSpot() const
    {
        return parkingSpotNum;
    }

    void Vehicle::setParkingSpot(int spot)
    {
        parkingSpotNum = spot;
    }

    std::istream &Vehicle::read(std::istream &istr = std::cin)
    {
        char userInput[256];
        if (isCsv())
        {
            if (istr.fail())
            {
                setEmpty();

            } else {
                istr.getline(userInput, 255, ',');
                setParkingSpot(stoi(userInput));
                istr.getline(userInput, 255, ',');
                if(licensePlate != nullptr)
                {
                    delete[] licensePlate;
                    licensePlate = nullptr;
                }
                licensePlate = new char[strlen(userInput) + 1];
                strcpy(licensePlate, userInput);
                int i = 0;
                while (licensePlate[i])
                {
                    licensePlate[i] = toupper(licensePlate[i]);
                    ++i;
                }
                istr.getline(userInput, 255, ',');
                setMakeModel(userInput);
            }
        } else {
            if (istr.fail())
            {
                setEmpty();

            } else{
                cout << "Enter Licence Plate Number: ";
                bool state = false;
                while (!state) {

                    istr.getline(userInput,256,'\n');

                    if (strlen(userInput) > 8 || strlen(userInput) <= 0) {
                        cout << "Invalid Licence Plate, try again: ";
                    } else {
                        delete[] licensePlate;
                        licensePlate = new char[strlen(userInput) + 1];
                        strcpy(licensePlate, userInput);
                        int i = 0;
                        while (licensePlate[i])
                        {
                            licensePlate[i] = toupper(licensePlate[i]);
                            ++i;
                        }
                        state = true;
                    }
                }
                state = false;
                cout << "Enter Make and Model: ";
                while (!state)
                {
                    istr.getline(userInput,256,'\n');
                    if (strlen(userInput) >= 2 && strlen(userInput) <= 60) {
                        setMakeModel(userInput);
                        state = true;

                    } else {
                        cout << "Invalid Make and model, try again: ";
                    }
                }
                setParkingSpot(0);
            }
        }
        return istr;
    }

    std::ostream &Vehicle::write(std::ostream &ostr = std::cout) const
    {
        if (isEmpty())
        {
            ostr << "Invalid Vehicle Object" << endl;

        } else {
            if (!isCsv())
            {
                ostr << "Parking Spot Number: ";
                if (parkingSpotNum == 0)
                {
                    cout << "N/A" << endl;

                } else {
                    cout << parkingSpotNum << endl;
                }
                ostr << "Licence Plate: " << licensePlate << endl;
                ostr << "Make and Model: " << makeNmodel << endl;
            } else {
                ostr << parkingSpotNum << "," << licensePlate << "," << makeNmodel << ",";
            }
        }

        return ostr;
    }

    bool operator==(const Vehicle &plate1, const Vehicle &plate2)
    {
        bool state = false;
        if (!plate1.isEmpty() && !plate2.isEmpty())
        {
//            if(!strcmp(plate1.getLicensePlate(),plate2.getLicensePlate()))
//            {
//                state = true;
//            }
            if (isIdentical(plate1.getLicensePlate(), plate2.getLicensePlate()))
            {
                state = true;
            }
        }
        return state;
    }

    bool operator==(const Vehicle &vehicle, const char *plateValue)
    {
        bool state = false;
        if (!vehicle.isEmpty() && plateValue != nullptr)
        {
//            if(!strcmp(vehicle.getLicensePlate(),plateValue))
//            {
//                state = true;
//            }
            if (isIdentical(vehicle.getLicensePlate(), plateValue))
            {
                state = true;
            }
        }
        return state;
    }

    Vehicle::~Vehicle()
    {
        delete[] licensePlate;
        licensePlate = nullptr;
        delete[] makeNmodel;
        makeNmodel = nullptr;
    }

    bool isIdentical(const char *firstString, const char *secondString)
    {
//        char *firstStringCopy = new char[strlen(firstString) + 1];
//        char *secondStringCopy = new char[strlen(secondString) + 1];
        char firstStringCopy[255];
        char secondStringCopy[255];
        strcpy(firstStringCopy, firstString);
        strcpy(secondStringCopy, secondString);

        int counter = 0;
        while (firstStringCopy[counter])
        {
            firstStringCopy[counter] = toupper(firstStringCopy[counter]);
            ++counter;
        }
        counter = 0;
        while (secondStringCopy[counter])
        {
            secondStringCopy[counter] = toupper(secondStringCopy[counter]);
            ++counter;
        }
        if (!strcmp(firstStringCopy, secondStringCopy))
        {
            return true;
        }

//        delete[] firstStringCopy;
//        delete[] secondStringCopy;
        return false;
    }
}