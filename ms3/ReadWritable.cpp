/* Citation and Sources... Final Project Milestone 4
Module: ReadWritable
Filename: ReadWritable.cpp
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

#include "ReadWritable.h"

namespace sdds
{
    ReadWritable::ReadWritable()
    {
        CSVflag = false;
    }

    bool ReadWritable::isCsv()const
    {
        return CSVflag;
    }

    void ReadWritable::setCsv(bool value)
    {
        CSVflag = value;
    }

    std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rw)
    {
        rw.write(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, ReadWritable& rw)
    {
        rw.read(istr);
        return istr;
    }

    ReadWritable::~ReadWritable()
    {

    }
}
