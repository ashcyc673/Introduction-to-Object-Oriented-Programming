/* Citation and Sources... Final Project Milestone 4
Module: ReadWritable
Filename: ReadWritable.h
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

#ifndef MS3_READWRITABLE_H
#define MS3_READWRITABLE_H
#include <iostream>


namespace sdds
{
    class ReadWritable {
        bool CSVflag;

    public:
        ReadWritable();
        virtual ~ReadWritable();
        bool isCsv()const;
        void setCsv(bool value);
        virtual std::istream& read(std::istream& istr) = 0;
        virtual std::ostream& write(std::ostream& ostr) const = 0;
    };
    std::ostream& operator<<(std::ostream& ostr, const ReadWritable&);
    std::istream& operator>>(std::istream& istr, ReadWritable&);
}



#endif //MS3_READWRITABLE_H
