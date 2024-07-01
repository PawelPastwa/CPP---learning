#ifndef LAB_2_PD_ZLAB03_H
#define LAB_2_PD_ZLAB03_H

#include <string>
#include <iostream>

using namespace std;

class Prostokat {
protected:
    string nazwa;
    double bok1, bok2;
    bool poprawny;
    double obwod, pole;

    bool czyPoprawny(double bok1, double bok2);

    void obliczObwod();

    void obliczPole();

public:
    Prostokat(string n = "?", double a = 1, double b = 2);

    virtual ~Prostokat();

    bool czyPoprawny();

    const string &jakaNazwa();

    double podajPole() const;

    double podajObwod();

    bool zmienBoki(double a, double b);

    virtual std::string doTekstu();

    Prostokat & operator++(int);

    bool operator!() {return czyPoprawny();}

    bool operator<(const Prostokat &p) const;
};

ostream& operator<<(ostream & strumien, Prostokat & prostokat);
istream& operator>>(istream & strumien, Prostokat & prostokat);

#endif //LAB_2_PD_ZLAB03_H
