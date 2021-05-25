//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NEE
// Date:           06/14/2020
//==============================================
// Workshop:   3
// Part:      2
//==============================================

#ifndef W3P1_CARGO_H
#define W3P1_CARGO_H


namespace sdds
{
    const double MAX_WEIGHT = 777.555;
    const double MIN_WEIGHT = 44.2222;
    const int MAX_DESC = 20;

    class Cargo
    {

        char m_desc[MAX_DESC + 1];
        double m_weight;

    public:
        void initialize(const char* desc, double weight);
        const char* getDesc() const;
        double getWeight() const;
        void setDesc(const char* description);
        void setWeight(double weight);
    };
}


#endif //W3P1_CARGO_H
