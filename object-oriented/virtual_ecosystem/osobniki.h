#ifndef LAB_2_PD_OSOBNIKI_H
#define LAB_2_PD_OSOBNIKI_H

#include "organizm.h"
#include "mieszkaniec.h"


class Glon : protected Organizm, public Mieszkaniec {
public:
    Glon();

    virtual RodzajMieszkanca kimJestes() final;

    virtual ZamiarMieszkanca
    wybierzAkcje(Sasiedztwo sasiedztwo);

    virtual Mieszkaniec *dajPotomka();

    virtual void przyjmijZdobycz
            (Mieszkaniec *mieszkaniec);
};

class Grzyb : protected Organizm, public Mieszkaniec {
public:
    Grzyb();

    virtual RodzajMieszkanca kimJestes() final;

    virtual ZamiarMieszkanca
    wybierzAkcje(Sasiedztwo sasiedztwo);

    virtual Mieszkaniec *dajPotomka();

    virtual void przyjmijZdobycz
            (Mieszkaniec *mieszkaniec);
};

class Bakteria : protected Organizm, public Mieszkaniec {
public:
    Bakteria();

    virtual RodzajMieszkanca kimJestes() final;

    virtual ZamiarMieszkanca
    wybierzAkcje(Sasiedztwo sasiedztwo);

    virtual Mieszkaniec *dajPotomka();


    virtual void przyjmijZdobycz
            (Mieszkaniec *mieszkaniec);
};


#endif //LAB_2_PD_OSOBNIKI_H

//Nisza nisza;
//nisza.przyjmijLokatora(new Bakteria());
//
//cout << "Kto w niszy: "
//<< nisza.ktoTuMieszka() << endl;
//cout << "Czy zywy: "
//<< nisza.lokatorZywy() << endl;
//
//Sasiedztwo sasiedztwo;
//sasiedztwo.okreslSasiada(P, GLON);
//sasiedztwo.okreslSasiada(PG, GRZYB);
//sasiedztwo.okreslSasiada(G, GRZYB);
//sasiedztwo.okreslSasiada(LG, GLON);
//sasiedztwo.okreslSasiada(L, BAKTERIA);
//sasiedztwo.okreslSasiada(LD, BAKTERIA);
//sasiedztwo.okreslSasiada(D, GLON);
//sasiedztwo.okreslSasiada(PD, PUSTKA);
//
//ZamiarMieszkanca zamiar = nisza.aktywujLokatora(sasiedztwo);
//
//cout << "Akjca: " << zamiar.akcja << " gdzie: "
//<< zamiar.gdzie << endl;
//
//cout << endl;
