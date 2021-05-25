/* Citation and Sources... Final Project Milestone 1
Module: Menu
Filename: Utils.cpp
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


}
