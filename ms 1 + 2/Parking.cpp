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
#include "Parking.h"

namespace sdds
{
    Parking::Parking()
    {
        m_filename = nullptr;
        m_parkingMenu = nullptr;
        m_vehiSeleMenu = nullptr;
    }

    Parking::Parking(const char* filename)
    {
        if(filename == nullptr || strlen(filename) == 0)
        {
            *this = Parking();

            cout << "Error in data file" << endl;

        } else{

            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename,filename);

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
        m_parkingMenu = new Menu("Parking Menu, select an action:");
        m_parkingMenu->add("Park Vehicle");
        m_parkingMenu->add("Return Vehicle");
        m_parkingMenu->add("List Parked Vehicles");
        m_parkingMenu->add("Close Parking (End of day)");
        m_parkingMenu->add("Exit Program");
    }

    void Parking::vcMenu()
    {
        m_vehiSeleMenu = new Menu("Select type of the vehicle:",1);
        m_vehiSeleMenu->add("Car");
        m_vehiSeleMenu->add("Motorcycle");
        m_vehiSeleMenu->add("Cancel");
    }

    int Parking::run()
    {
        if(!isEmpty())
        {
            bool state = false;
            while(!state)
            {
                parkStatus();
                int userChoice = m_parkingMenu->run();

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
           return 0;

        }
        return 1;
    }

    bool Parking::isEmpty() const
    {
        return (m_filename == nullptr && m_parkingMenu == nullptr && m_vehiSeleMenu == nullptr);
    }

    void Parking::parkStatus()
    {
        cout << "****** Seneca Valet Parking ******" << endl;
    }

    void Parking::parkVehicle()
    {
        int userChoice = m_vehiSeleMenu->run();

        switch(userChoice)
        {
            case 1:
                cout << "Parking Car" << endl;
                break;
            case 2:
                cout << "Parking Motorcycle" << endl;
                break;
            case 3:
                cout << "Cancelled parking" << endl;
                break;
        }

    }

    void Parking::returnVehicle()
    {
        cout << "Returning Vehicle" << endl;
    }

    void Parking::listParkedVehicle()
    {
        cout << "Listing Parked Vehicles" << endl;
    }

    bool Parking::closeParking()
    {
        cout << "Closing Parking" << endl;
        return true;
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
            cout << "loading data from " << m_filename << endl;
            state = true;
        }
        return state;
    }

    void Parking::saveDataFile()
    {
        if(!isEmpty())
        {
            cout << "Saving data into " << m_filename << endl;
        }
    }

    Parking::~Parking()
    {
        saveDataFile();
        delete[] m_filename;
        m_filename = nullptr;
        delete m_parkingMenu;
        m_parkingMenu = nullptr;
        delete m_vehiSeleMenu;
        m_vehiSeleMenu = nullptr;
    }
}
