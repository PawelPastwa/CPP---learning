#ifndef LAB_2_PD_ZLAB06_H
#define LAB_2_PD_ZLAB06_H

#include "zlab03.h" //(lesson3)
#include <iostream>

using namespace std;

class Obliczenia {
protected:
    const double pi = 3.14;
public:
    virtual double promienKolaWgPola() = 0;

    virtual double promienOkreguWgObwodu() = 0;

    virtual ~Obliczenia();
};

class Kwadrat : public Prostokat, public Obliczenia{
public:

    Kwadrat(string nazwa = "?", double bok = 0)
            : Prostokat(nazwa, bok, bok) {}

    ~Kwadrat() {
        cout << "Kwadrat: " << nazwa << " konczy dzialanie" << endl;
    }

    string doTekstu() override;
    double promienKolaWgPola() override;
    double promienOkreguWgObwodu() override;
};


#endif //LAB_2_PD_ZLAB06_H
