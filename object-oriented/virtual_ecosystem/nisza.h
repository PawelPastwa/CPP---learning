#ifndef LAB_2_PD_NISZA_H
#define LAB_2_PD_NISZA_H

#include "sasiedztwo.h"
#include "mieszkaniec.h"
#include "srodowisko.h"

class Nisza {
private:
    Mieszkaniec *lokator;

public:
    Nisza();

    Nisza(Nisza &innaNisza);

    ~Nisza();

    Nisza &operator=(Nisza &innaNisza);

    void przyjmijLokatora(Mieszkaniec *lokatorBezdomny);

    Mieszkaniec *oddajLokatora();

    bool zajeta() const { return lokator != nullptr; }

    RodzajMieszkanca ktoTuMieszka() {
        return zajeta() ? lokator->kimJestes() : PUSTKA;
    }

    bool lokatorZywy() const;

    char jakiSymbol() const;

private:

    friend void Srodowisko::wykonajAkcje(unsigned int wiersz, unsigned int kolumna);

    ZamiarMieszkanca aktywujLokatora(
            Sasiedztwo sasiedztwo) {
        return lokator->wybierzAkcje(sasiedztwo);
    }

    void przyjmijZdobycz(Mieszkaniec *ofiara) {
        lokator->przyjmijZdobycz(ofiara);
    }

    Mieszkaniec *wypuscPotomka() {
        return lokator->dajPotomka();
    }
};


#endif //LAB_2_PD_NISZA_H




//static Nisza n1, n2, n3;
//
//static char sep = UstawieniaSymulacji::
//pobierzUstawienia().znakSeparator;
//
//void wyswietlNisze() {
//    cout << n1.jakiSymbol() << sep
//         << n2.jakiSymbol() << sep
//         << n3.jakiSymbol() << endl;
//}
//
//int main() {
//    cout << "Puste nisze: ";
//    wyswietlNisze();
//
//    cout << "Lokowanie mieszkancow: ";
//    n1.przyjmijLokatora(new Glon());
//    n3.przyjmijLokatora(new Grzyb());
//    wyswietlNisze();
//
//    cout << "Przesuwanie lokatorow: ";
//    n2 = n1;
//    wyswietlNisze();
//
//    cout << "Przesuwanie lokatorow:";
//    n3 = n2;
//    wyswietlNisze();
//
//    cout << endl;
//    return 0;
//}
