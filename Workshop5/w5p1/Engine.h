//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           06/21/2020
//==============================================
// Workshop:   5
// Part:      1
//==============================================

#ifndef W5P1_ENGINE_H
#define W5P1_ENGINE_H

namespace sdds
{
    const int TYPE_MAX_SIZE = 30;
    class Engine {

        double m_size;
        char m_type[TYPE_MAX_SIZE + 1];

    public:

        Engine();
        Engine(const char* type, double size);
        double get() const;
        void display() const;

    };




}



#endif //W5P1_ENGINE_H
