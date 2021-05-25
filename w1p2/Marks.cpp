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

#include "Marks.h"
#include "Utils.h"
#include<iostream>
#include <cstring>
#include<algorithm>


using namespace std;

namespace sdds {
    int getNumberOfMarks() {
        char userInput[256];
        cout << "Please enter the number of marks: ";
        cin >> userInput;
        cin.clear();
        cin.ignore(1000, '\n');

        bool state = false;
        int marks;

        while (!state) {
            if (isNumber(userInput)) {
                marks = stoi(userInput);

                if (marks < 5 || marks > 50) {
                    cout << "Invalid value (5<=value<=50), try again: ";
                    cin >> userInput;
                    cin.clear();
                    cin.ignore(1000, '\n');
                } else {
                    state = true;
                }
            } else if (isString(userInput)) {
                cout << "Invalid Number, try again: ";
                cin >> userInput;
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                cout << "Invalid trailing characters, try again: ";
                cin >> userInput;
                cin.clear();
                cin.ignore(1000, '\n');
            }

        }

        return marks;
    }

    int getMarkValue() {
        int userInput;
        cin >> userInput;
        while (userInput < 0 || userInput > 100) {
            cout << "Invalid value (0<=value<=100), try again: ";
            cin >> userInput;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        return userInput;
    }


    int passingMark(int mark[], int length) {
        int counter = 0;
        for (int i = 0; i < length; i++) {
            if (mark[i] >= 50) {
                counter++;
            }

        }
        return counter;
    }


    void markstat() {

        char name[41];


        cout << "Mark Stats Program." << endl;
        cout << endl;

        cout << "Please enter the assessment name: ";
        cin.getline(name, 40, '\n');


        int numberOfMarks = getNumberOfMarks();
        int marks[numberOfMarks];

        cout << "Please enter " << numberOfMarks << " marks (0<=Mark<=100):" << endl;


        for (int i = 0; i < numberOfMarks; i++) {

            cout << i + 1 << "> ";
            marks[i] = getMarkValue();

        }

        sort(marks, marks + numberOfMarks,greater<int>());


        cout << "Thank you..." << endl;
        cout << "Assessment Name: " << name << endl;
        cout << "----------------" << endl;

        for (int i = 0; i < numberOfMarks; i++) {
            cout << marks[i];
            if (i != numberOfMarks - 1) {
                cout << ", ";
            }

        }

        cout << endl;
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << "Average: " << average(marks, numberOfMarks) << endl;
        cout << "Number of Passing Marks: " << passingMark(marks, numberOfMarks) << endl;
    }

}