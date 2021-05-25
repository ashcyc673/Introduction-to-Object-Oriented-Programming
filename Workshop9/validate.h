//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           07/23/2020
//==============================================
// Workshop:   9
// Part:      1
//==============================================

#ifndef WORKSHOP9_VALIDATE_H
#define WORKSHOP9_VALIDATE_H

namespace sict
{
    template <typename T>
    bool validate(const T& greThanMin, T testArr[], int arrSize, bool results[])
    {
       bool state = true;
        for(int i = 0; i < arrSize; i++)
        {
            if(testArr[i] >= greThanMin)
            {
                results[i] = true;

            } else
            {
                results[i] = false;
                state = false;
            }
        }
      return state;
    }
}

#endif //WORKSHOP9_VALIDATE_H
