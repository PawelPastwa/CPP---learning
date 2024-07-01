#ifndef LAB_2_PD_USTAWIENIA_H
#define LAB_2_PD_USTAWIENIA_H

enum RodzajMieszkanca {
    GLON, GRZYB, BAKTERIA, PUSTKA, SCIANA,
    TRUP, NIEZNANE
};

enum AkcjaMieszkanca {
    POTOMEK, POLOWANIE, ROZKLAD, NIC
};

enum Polozenie {
    P = 0, PG = 1, G = 2, LG = 3, L = 4, LD = 5, D = 6, PD = 7,
    NIGDZIE = 8
};

class UstawieniaSymulacji {
public:
    const char
            znakGlon = '*',
            znakGrzyb = '#',
            znakBakteria = '@',
            znakTrup = '+',
            znakNieokreslony = '?',
            znakPustaNisza = '_',
            znakSeparator = ' ';

    unsigned short
            glonZycieMin = 5,
            glonZycieMax = 10,
            glonKosztPotomka = 2,
            glonLimitPosilkow = 6,

            grzybZycieMin = 40,
            grzybZycieMax = 60,
            grzybKosztPotomka = 3,
            grzybLimitPosilkow = 30,

            bakteriaZycieMin = 25,
            bakteriaZycieMax = 40,
            bakteriaKosztPotomka = 3,
            bakteriaLimitPosilkow = 10;

    bool poprawnyZnakNiszy(char znak) const {
        return znak == znakGlon ||
               znak == znakGrzyb ||
               znak == znakBakteria ||
               znak == znakTrup ||
               znak == znakPustaNisza;

    }

    bool poprawnySeparator(char znak) const {
        return znak == znakSeparator;
    }

private:
    UstawieniaSymulacji() {}

    UstawieniaSymulacji(UstawieniaSymulacji &);

public:
    static UstawieniaSymulacji &pobierzUstawienia() {
        static UstawieniaSymulacji ustawienia;
        return ustawienia;
    }
};


#endif //LAB_2_PD_USTAWIENIA_H



//1. Dostęp do obiektu klasy UstawienaSymulacji
//UstawieniaSymulacji &UST1
//        = UstawieniaSymulacji::pobierzUstawienia();
//UstawieniaSymulacji &UST2
//        = UstawieniaSymulacji::pobierzUstawienia();
//UstawieniaSymulacji &UST3
//        = UstawieniaSymulacji::pobierzUstawienia();


//void wyswietl(UstawieniaSymulacji &UST) {
//    cout << "Znak glon:" << UST.znakGlon
//         << " zycieMin=" << UST.glonZycieMin
//         << " zycieMax=" << UST.glonZycieMax << endl;
//}

//int main

//cout << "Pobranie ustawien 3x" << endl;
//cout << "UST1: ";
//wyswietl(UST1);
//cout << "UST2: ";
//wyswietl(UST2);
//cout << "UST3: ";
//wyswietl(UST3);
//
//cout << endl << "Zmiana wartosci tylko 1x" << endl;
//UST2.glonZycieMax = 100;
//cout << "UST1: ";
//wyswietl(UST1);
//cout << "UST2: ";
//wyswietl(UST2);
//cout << "UST3: ";
//wyswietl(UST3);
