#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct student {
    string imie;
    string nazwisko;
    int punkty;
};

enum typ {
    rosnaco, malejaco
};

int wczytajStudentow(student *&tab);

void wyswietlStudentow(student *tab, int n);

void usunTabliceStudentow(student *&tab);

void sortowanieQuickSort(student *tab, int l, int p, typ tryb);

int main() {

    int jak;
    student *tab;
    int studenci = wczytajStudentow(tab);

    cout<<"Podaj sposob sortowania"<<endl<<"0 - rosnaca"<<endl<<"1 - malejaco"<<endl;
    cin>>jak;
    typ sortowanie = static_cast<typ>(jak);

    cout << "Tablica przed sortowaniem:" << endl;
    wyswietlStudentow(tab, studenci);
    sortowanieQuickSort(tab, 0, studenci-1, sortowanie);
    cout << "Tablica po sortowaniu:" << endl;
    wyswietlStudentow(tab, studenci);
    usunTabliceStudentow(tab);

    return 0;
}

int wczytajStudentow(student *&tab) {
    string sciezka, linia, pomoc;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;

    sciezka = "studenci.csv";

    plik.open(sciezka);
    plik >> liczbaStudentow;

    tab = new student[liczbaStudentow];

    for (int i = 0; i < 2; i++)
        plik >> sredniki;

    for (int i = 0; i < liczbaStudentow; i++) {
        plik >> linia;

        stringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty = atoi(pomoc.c_str());
    }
    plik.close();

    return liczbaStudentow;
}

void wyswietlStudentow(student *tab, int n) {
    for (int i = 0; i < n; i++) {
        cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << endl;
    }
}

void usunTabliceStudentow(student *&tab) {
    delete[] tab;
}

void sortowanieQuickSort(student *tab, int l, int p, typ tryb) {
    if (l < p) {
        int sr = (int) (l + p) / 2;
        int pivot = tab[sr].punkty;
        swap(tab[sr], tab[p]);
        int g = l;

        for (int i = l; i < p; i++) {
            if (tryb == rosnaco) {
                if (tab[i].punkty < pivot) {
                    swap(tab[g], tab[i]);
                    g++;
                }
            }

            else
                if (tab[i].punkty > pivot) {
                    swap(tab[g], tab[i]);
                    g++;
                }

        }

        swap(tab[g], tab[p]);

            if (l < g - 1)
                sortowanieQuickSort(tab, l, g - 1, tryb);
            if (g + 1 < p)
                sortowanieQuickSort(tab, g + 1, p, tryb);
    }
}
