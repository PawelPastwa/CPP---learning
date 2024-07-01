#include <iostream>
#include "zlab02.h"
#include <limits>
#include <typeinfo>
#include <cmath>
#include <random>

using namespace std;

void Zlab02::zadanie_2_3() {
    int a = -3;
    unsigned int b;
    b = 5;
    int int_min = numeric_limits<int>::min();
    int int_max = numeric_limits<int>::max();
    unsigned int unsigned_int_min
            = numeric_limits<unsigned int>::min();
    unsigned int unsigned_int_max
            = numeric_limits<unsigned int>::max();

    long int_zakres =
            static_cast<long>(int_max)
            - static_cast<long>(int_min);

    long unsigned_int_zakres =
            static_cast<long>(unsigned_int_max)
            - static_cast<long>(unsigned_int_min);

    cout << "Zmienna c1 jest typu: " << typeid(a).name()
         << " ma rozmiar: " << sizeof(a) << " bajtów"
         << endl << "Zakres tej zmiennej to: " << int_min
         << " -> " << int_max << ", to oznacza "
         << int_zakres << " różnych wartości" << endl
         << "Aktualna wartość zmiennej to: " << a
         << endl << endl;

    cout << "Zmienna c2 jest typu: " << typeid(b).name()
         << " ma rozmiar: " << sizeof(b) << " bajtów"
         << endl
         << "Zakres tej zmiennej to: " << unsigned_int_min
         << " -> " << unsigned_int_max << ", to oznacza "
         << unsigned_int_zakres << " różnych wartości"
         << endl
         << "Aktualna wartość zmiennej to: " << b << endl
         << endl;
}

void Zlab02::zadanie_2_4() {
    int a = 5, b = 3;
    int c = a / b;
    double d = a / b;
    double e = static_cast<double>(a) / static_cast<double>(b);

    cout << "a=" << a << " b=" << b << endl
         << " a/b=" << c << endl
         << " a/b=" << d << endl
         << " a/b=" << e << endl;
}

void Zlab02::zadanie_2_5() {
    cout.precision(20);
    double eps = numeric_limits<double>::min();
    cout << "Dzielenie z dokładnością: " << eps << endl;
    double x, y;
    cout << "Podaj dzielną: ";
    cin >> x;
    cout << "Podaj dzielnik: ";
    cin >> y;
    if (fabs(y) > eps)
        cout << x << "/" << y << "=" << x / y << endl;
    else
        cout << "Dzielnik jest za mały" << endl;
}

void Zlab02::menu() {
    unsigned short wybor;

    do {
        cout << "Ktore zadanie uruchomic?" << endl
             << "3  -> zadanie 2.3" << endl
             << "4  -> zadanie 2.4" << endl
             << "5  -> zadanie 2.5" << endl
             << "6  -> zadanie 2.7" << endl
             << "7  -> zadanie 2.8" << endl
             << "8  -> zadanie 2.9" << endl
             << "9  -> zadanie 2.10" << endl
             << "10 -> pobierz liczbe" << endl;
        cin >> wybor;
    } while (wybor < 3 || wybor > 10);

    switch (wybor) {
        case 3 :
            zadanie_2_3();
            break;
        case 4 :
            zadanie_2_4();
            break;
        case 5 :
            zadanie_2_5();
            break;
        case 6:
            zadanie_2_7();
            break;
        case 7:
            zadanie_2_8();
            break;
        case 8:
            zadanie_2_9();
            break;
        case 9:
            short a, b;
            cout<<"Podaj dolna granice losowanych liczb"<<endl;
            cin>>a;
            cout<<"Podaj gorna granice losowanych liczb"<<endl;
            cin>>b;

            zadanie_2_10(a, b);
            break;
        case 10:
            pobierzLiczbe();
            break;
        default:
            cout << "Nie ma takiego zadania" << endl;
    }
}

void Zlab02::zadanie_2_7() {
    long liczba1 = 3, liczba2 = -5, liczba3 = 0;

    long *wskaznikDoLong;
    wskaznikDoLong = nullptr;

    cout << "liczba1=" << liczba1
         << " liczba2=" << liczba2
         << " liczba3=" << liczba3 << endl;

    wskaznikDoLong = &liczba2;

    *wskaznikDoLong = 10;

    cout << "liczba1=" << liczba1
         << " liczba2=" << liczba2
         << " liczba3=" << liczba3 << endl;

    wskaznikDoLong = &liczba3;

    *wskaznikDoLong = liczba1;

    cout << "liczba1=" << liczba1
         << " liczba2=" << liczba2
         << " liczba3=" << liczba3 << endl;

    wskaznikDoLong = &liczba1;

    liczba2 = *wskaznikDoLong;

    cout << "liczba1=" << liczba1
         << " liczba2=" << liczba2
         << " liczba3=" << liczba3 << endl;
}

void Zlab02::zadanie_2_8() {
    long liczba1 = 3, liczba2 = -5, liczba3 = 0;

    cout << "liczba1=" << liczba1
         << " liczba2=" << liczba2
         << " liczba3=" << liczba3 << endl;

    long &referencjaDoLong = liczba2;

    referencjaDoLong = 10;

    cout << "liczba1=" << liczba1
         << " liczba2=" << liczba2
         << " liczba3=" << liczba3 << endl;

    long &referencjaDoLongInna = liczba3;

    referencjaDoLongInna = liczba1;

    cout << "liczba1=" << liczba1
         << " liczba2=" << liczba2
         << " liczba3=" << liczba3 << endl;

    long &referencjaDoLongKolejna = liczba1;

    liczba2 = referencjaDoLongKolejna;

    cout << "liczba1=" << liczba1
         << " liczba2=" << liczba2
         << " liczba3=" << liczba3 << endl;
}

void Zlab02::zadanie_2_9() {
    const short N = 10;
    int tablica[N];

    random_device maszynkaLosujaca;
    uniform_int_distribution<short> dystrybucja(-3, 4);

    for (unsigned short i = 0; i < N; i++)
        tablica[i] = dystrybucja(maszynkaLosujaca);

    for (int j: tablica) cout << j << " ";

    cout << endl;
}

void Zlab02::zadanie_2_10(short min, short max) {
    const short N = 10;
    int tab[N];

    random_device maszynka;
    uniform_int_distribution<short> dystr(min, max);

    tab[0] = dystr(maszynka);

    for (unsigned short i = 1; i < N; i++)
        while ((tab[i] = dystr(maszynka)) < tab[i - 1]);

    for (int liczba: tab) cout << liczba << " ";
}

double Zlab02::pobierzLiczbe() {
    double x = 0;
    bool sukces = true;
    string linia;

    do {
        if (!sukces) cout << "!To ma być liczba." << endl;
        getline(cin, linia);
        try {
            x = stod(linia);
            sukces = true;
        } catch (const invalid_argument &) {
            sukces = false;
        }
    } while (!sukces);

    return x;
}
