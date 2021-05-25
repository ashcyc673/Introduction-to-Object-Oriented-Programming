/* Citation and Sources... Final Project Milestone 4
Module: Utils
Filename: Utils.cpp
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

#include "Utils.h"


namespace sdds
{
    bool isNumber(char userInput[]) {
        bool state = true;
        int userInputLen = strlen(userInput);
        if (userInputLen == 0) {
            state = false;
        } else {
            for (int i = 0; i < userInputLen; i++) {
                if (!isdigit(userInput[i]))
                {
                    state = false;
                    break;
                }
            }
        }
        return state;
    }

    bool getUserDecision()
    {
        char input[256];

        bool state = false;
        bool result = false;

        while(!state)
        {
            std::cin >> input;
            std::cin.clear();
            if(strlen(input) == 1)
            {
                if(input[0] == 'Y' || input[0]== 'y')
                {
                    state = true;
                    result = true;

                } else if(input[0] == 'N' || input[0]== 'n')
                {
                    state = true;
                }
                else
                {
                    std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                }
            }
            else
            {
                std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        }
        return result;
    }
}
