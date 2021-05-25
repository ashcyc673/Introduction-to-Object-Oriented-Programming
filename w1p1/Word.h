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

#ifndef C___PROJECTS_WORD_H
#define C___PROJECTS_WORD_H
#include <iostream>
#include <iomanip>


namespace sdds
{
    const int MAX_WORD_LEN = 21;
    const int MAX_NO_OF_WORDS = 500;
    const int SORT_BY_OCCURANCE = 1;
    const int SORT_ALPHABETICALLY = 0;

    struct Word{
        char letters[MAX_WORD_LEN];
        int count;
    };


    int searchWords(const Word words[], int num, const char word[]);
    void addWord(Word words[], int* index, const char newWord[]);
    void print(const Word* w, bool gotoNextLine, int len);
    int findMaxLen(const Word words[], int noOfWords);
    void listWords(const Word words[], int noOfWords, const char* theTitle);
    void swap(Word* p1, Word* p2);
    void sort(Word words[], int cnt, int sortType);
    int totalCount(const Word* words, int num);
    void wordStats();
    void programTitle();
}


#endif //C___PROJECTS_WORD_H
