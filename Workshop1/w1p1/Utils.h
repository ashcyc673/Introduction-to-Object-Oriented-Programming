//==============================================
// Name:           Chiao Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           05/23/2020
//==============================================
// Workshop:     1
// Part:      1
//==============================================

#ifndef C___PROJECTS_UTILS_H
#define C___PROJECTS_UTILS_H
#include <iostream>
#include <iomanip>

namespace sdds
{
    char ToLower(char ch);
    int StrCmp(const char* s1, const char* s2);
    void StrCpy(char* des, const char* src);
    int StrLen(const char* str);
    bool isAlpha(char ch);
    void trim(char word[]);
    void toLowerCaseAndCopy(char des[], const char source[]);
    void title(const char* value, int len);
    void endList();
    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);


};




#endif //C___PROJECTS_UTILS_H
