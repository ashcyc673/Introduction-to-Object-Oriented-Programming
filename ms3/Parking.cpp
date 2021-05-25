/* Citation and Sources... Final Project Milestone 6
Module: Parking
Filename: Parking.cpp
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
#include "Parking.h"
#include <iomanip>


namespace sdds
{
    Parking::Parking()
    {
        m_filename = nullptr;
        m_parkingMenu = nullptr;
        m_vehiSeleMenu = nullptr;
        numParkedVehicle = 0;
        numSpot = 0;
    }

    Parking::Parking(const char* filename, int noOfSpots)
    {
        if(filename == nullptr || strlen(filename) == 0 || noOfSpots < 10 || noOfSpots > MAX_PARKING_SPOT)
        {
            *this = Parking();
            cout << "Error in data file" << endl;

        } else{
            numParkedVehicle = 0;
            numSpot = noOfSpots;
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename,filename);
            for(int i = 0; i < numSpot; i++)
            {
                parkSpot[i] = nullptr;
            }

            if(loadDataFile())
            {
                pkMenu();
                vcMenu();
            } else{

                cout << "Error in data file" << endl;
                *this = Parking();
            }
        }
    }

    void Parking::pkMenu()
    {
        m_parkingMenu = Menu("Parking Menu, select an action:");
        m_parkingMenu.add("Park Vehicle");
        m_parkingMenu.add("Return Vehicle");
        m_parkingMenu.add("List Parked Vehicles");
        m_parkingMenu.add("Close Parking (End of day)");
        m_parkingMenu.add("Exit Program");

    }

    void Parking::vcMenu()
    {
        m_vehiSeleMenu = Menu("Select type of the vehicle:",1);
        m_vehiSeleMenu.add("Car");
        m_vehiSeleMenu.add("Motorcycle");
        m_vehiSeleMenu.add("Cancel");
    }

    int Parking::run()
    {
        if(!isEmpty())
        {
            bool state = false;
            while(!state)
            {
                parkStatus();
                int userChoice = m_parkingMenu.run();

                switch(userChoice)
                {
                    case 1:
                        parkVehicle();
                        break;
                    case 2:
                        returnVehicle();
                        break;
                    case 3:
                        listParkedVehicle();
                        break;
                    case 4:
                        if(closeParking() == true)
                        {
                            state = true;
                        }
                        break;
                    case 5:
                        if(exitParkingApp() == true)
                        {
                            cout << "Exiting program!" << endl;
                            state = true;
                        }
                        break;
                }
            }
            cin.clear();
            cin.ignore(1000,'\n');
            return 0;

        }
        return 1;
    }

    bool Parking::isEmpty() const
    {
        return (m_filename == nullptr);
    }

    void Parking::parkStatus()
    {
        cout << "****** Seneca Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout << left << setw(4) << numSpot - numParkedVehicle;
        cout << " *****" << endl;
    }

    void Parking::parkVehicle()
    {
        if(numParkedVehicle == numSpot)
        {
            cout << "Parking is full" << endl;
        }
        else{
            int userChoice = m_vehiSeleMenu.run();

            switch(userChoice)
            {
                case 1:

                    for(int i = 0; i < numSpot; i++)
                    {
                       if(parkSpot[i] == nullptr)
                       {
                           parkSpot[i] = new Car();
                           parkSpot[i]->setCsv(false);
                           parkSpot[i]->read(cin);
                           parkSpot[i]->setParkingSpot(i+1);
                           numParkedVehicle++;
                           cout << endl;
                           cout << "Parking Ticket" << endl;
                           parkSpot[i]->write(cout);
                           cout << endl;
                           break;
                       }
                    }
                    break;
                case 2:
                    for(int i = 0; i < numSpot; i++)
                    {
                        if(parkSpot[i] == nullptr)
                        {
                            parkSpot[i] = new Motorcycle();
                            parkSpot[i]->setCsv(false);
                            parkSpot[i]->read(cin);
                            parkSpot[i]->setParkingSpot(i+1);
                            numParkedVehicle++;
                            cout << endl;
                            cout << "Parking Ticket" << endl;
                            parkSpot[i]->write(cout);
                            cout << endl;
                            break;
                        }
                    }
                    break;
                case 3:
                    cout << "Parking cancelled" << endl;
                    break;
            }
        }

    }

    void Parking::returnVehicle() {

        cout << "Return Vehicle" << endl;
        cout << "Enter Licence Plate Number: ";
        char LPlate[256];
        bool state = false;
        while (!state)
        {
            cin.getline(LPlate, 255, '\n');
            int licPlateLength = strlen(LPlate);
            if (licPlateLength > 8 || licPlateLength < 1) {
                cout << "Invalid Licence Plate, try again: ";
            } else {
                state = true;
            }
        }
        for(int i = 0; i < numSpot; i++)
        {
            if(*parkSpot[i] == LPlate)
            {
                cout << endl;
                cout << "Returning: " << endl;
                parkSpot[i]->write(cout);
                numParkedVehicle--;
                delete parkSpot[i];
                parkSpot[i] = nullptr;
                break;
            } else
            {
                if(i == numSpot-1)
                {
                    cout << "License plate " << LPlate << " Not found" << endl;
                }
            }
        }
        cout << endl;
    }

    void Parking::listParkedVehicle()
    {
        cout << "*** List of parked vehicles ***" << endl;
        for(int i = 0; i < numSpot; i++)
        {
            if(parkSpot[i] != nullptr)
            {
                parkSpot[i]->write(cout);
                cout << "-------------------------------" << endl;
            }
        }
    }

    bool Parking::closeParking()
    {
        char userInput[255];
        bool state = false;
        bool check = false;

        if(isEmpty())
        {
            cout << "Closing Parking" << endl;
            cout << endl;

            return true;
        } else
        {
            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
            cout << "Are you sure? (Y)es/(N)o: ";

            while(!state)
            {
                cin >> userInput;
                if(strlen(userInput) == 1)
                {
                    if(userInput[0] == 'n' || userInput[0] == 'N')
                    {
                        check = false;
                        state = true;
                        cout << "Aborted!" << endl;
                    }
                    else if(userInput[0] == 'y' || userInput[0] == 'Y')
                    {
                        cout << "Closing Parking" << endl;
                        cout << endl;
                        for(int i=0; i < numParkedVehicle; i++)
                        {
                            cout << "Towing request"<< endl;
                            cout << "*********************" << endl;
                            parkSpot[i]->write(cout);
                            delete parkSpot[i];
                            parkSpot[i] = nullptr;
                            if (i < numParkedVehicle - 1) {
                                cout << endl;
                            }
                        }
                        check = true;
                        state = true;

                    } else
                    {
                        cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                    }
                } else
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }

        }
        return check;

    }

    bool Parking::exitParkingApp()
    {
        char userInput[255];
        bool state = false;
        bool check = false;

        cout << "This will terminate the program!" <<  endl;
        cout << "Are you sure? (Y)es/(N)o: ";

        while(!state)
        {
            cin >> userInput;
            if(strlen(userInput) == 1)
            {
                if(userInput[0] == 'n' || userInput[0] == 'N')
                {
                    check = false;
                    state = true;
                }
                else if(userInput[0] == 'y' || userInput[0] == 'Y')
                {
                    check = true;
                    state = true;

                } else
                {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                }
            } else
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
        }
        return check;

    }

    bool Parking::loadDataFile()
    {
        bool state = false;
        if(!isEmpty())
        {
            ifstream fin(m_filename);
            if(fin.is_open())
            {
                while(fin.good())
                {
                    char input[256];
                    fin.getline(input,255,',');
                    if(fin.bad())
                    {
                        fin.clear();
                        fin.ignore(1000,'\n');
                        delete[] m_filename;
                        m_filename = nullptr;
                        return false;
                    }
                    if(input[0] == 'M')
                    {
                        for(int i = 0; i < numSpot; i++)
                        {
                            if(parkSpot[i] == nullptr)
                            {
                                parkSpot[i] = new Motorcycle();
                                numParkedVehicle++;
                                parkSpot[i]->setCsv(true);
                                parkSpot[i]->read(fin);
                                parkSpot[i]->setCsv(false);
                                state = true;
                                break;
                            }
                        }
                    }
                    else if(input[0] == 'C')
                    {
                        for(int i = 0; i < numSpot; i++)
                        {
                            if(parkSpot[i] == nullptr)
                            {
                                parkSpot[i] = new Car();
                                numParkedVehicle++;
                                parkSpot[i]->setCsv(true);
                                parkSpot[i]->read(fin);
                                parkSpot[i]->setCsv(false);
                                state = true;
                                break;
                            }
                        }
                    }
                }
            }

          state = true;
        }
        return state;
    }

    void Parking::saveDataFile()
    {
        if(!isEmpty())
        {
            ofstream fout(m_filename);
            if(fout.is_open())
            {
                for(int i = 0; i < numSpot; i++)
                {
                    if(parkSpot[i] != nullptr)
                    {
                        if(fout.good())
                        {
                            parkSpot[i]->setCsv(true);
                            parkSpot[i]->write(fout);
                        }
                    }
                }
            }
        }
    }

    Parking::~Parking()
    {
        saveDataFile();
        delete[] m_filename;
        m_filename = nullptr;

        for(int i = 0; i < numSpot; i++)
        {
            delete parkSpot[i];
            parkSpot[i] = nullptr;
        }

    }
}
