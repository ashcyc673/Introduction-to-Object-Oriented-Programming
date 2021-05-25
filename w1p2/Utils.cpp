//==============================================
// Name:           Chiao Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           05/31/2020
//==============================================
// Workshop:     1
// Part:      2
//==============================================

#include "Utils.h"
#include <cstring>
using namespace std;

namespace sdds {

    bool isDigit(char singleChar) {
        bool state = false;
        char digit[] = "0123456789";
        int digitLen = strlen(digit);
        for (int i = 0; i < digitLen; i++) {
            if (singleChar == digit[i]) {
                state = true;
                break;
            }

        }
        return state;
    }


    bool isChar(char singleChar) {
        bool state = false;
        char charArr[] = "qwertyuiopasdfghjklzxcvbnm";
        int charLen = strlen(charArr);
        for (int i = 0; i < charLen; i++) {
            if (singleChar == charArr[i]) {
                state = true;
                break;
            }
        }
        return state;
    }

    bool isNumber(char userInput[]) {
        bool state = true;
        int userInputLen = strlen(userInput);
        if (userInputLen == 0) {
            state = false;
        } else {
            for (int i = 0; i < userInputLen; i++) {
                if (!isDigit(userInput[i])) {
                    state = false;
                    break;
                }
            }
        }
        return state;
    }


    bool isString(char userInput[]) {
        bool state = true;
        int userInputLen = strlen(userInput);
        if (userInputLen == 0) {
            state = false;
        } else {
            for (int i = 0; i < userInputLen; i++) {
                if (!isChar(userInput[i])) {
                    state = false;
                    break;
                }
            }
        }
        return state;
    }


    float average(int mark[], int length) {

        float sum = 0;
        for (int i = 0; i < length; i++) {
            sum += mark[i];
        }

        float average = sum / length;

        return average;

    }
}