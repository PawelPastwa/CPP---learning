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

void wczytajStudentow(student *&tab, int* liczbaStudentow);

void wyswietlStudentow(student *tab, int n);

void usunTabliceStudentow(student *&tab);

void podzialZbioruNa2(student *tab, int n, int* srodek);

void podzialZbioruNa3(student *tab, int n, int* srodek, int* srodek2);

void menu();


int main() {

    menu();


    return 0;
}

void wczytajStudentow(student *&tab, int* liczbaStudentow) {
    string sciezka, linia, pomoc;
    ifstream plik;
    char sredniki;

    sciezka = "studenci.csv";
    plik.open(sciezka);
    plik >> *liczbaStudentow;

    tab = new student[*liczbaStudentow];

    for (int i = 0; i < 2; i++)
        plik >> sredniki;

    for (int i = 0; i < *liczbaStudentow; i++) {
        plik >> linia;
        stringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty = atoi(pomoc.c_str());
    }
    plik.close();
}

void wyswietlStudentow(student *tab, int n) {
    for (int i = 0; i < n; i++) {
        cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << endl;
    }
}

void usunTabliceStudentow(student *&tab) {
    delete tab;
}

void podzialZbioruNa2(student *tab, int n, int* srodek){

    int i = 0;
    int j = n-1;

    while(i != j)
    {
        if (tab[i].punkty <= 10 && tab[j].punkty <= 10)
            i++;
        else if (tab[i].punkty > 10 && tab[j].punkty > 10)
            j--;
        else if (tab[i].punkty > 10 && tab[j].punkty <= 10) {
            swap(tab[i], tab[j]);
            i++;
            j--;
        } else if (tab[i].punkty <= 10 && tab[j].punkty > 10){
            i++;
            j--;
        }
    }
    *srodek = j + 1;
}

void podzialZbioruNa3(student *tab, int n, int* srodek, int* srodek2){

    int m, l = 0;
    int p = n - 1;

    while (m != p+1)
    {
        if (tab[m].punkty % 3 == 0){
            swap(tab[m], tab[l]);
            l++;
            m++;
            if (tab[l+1].punkty % 3 != 0)
                *srodek = l;
        } else if(tab[m].punkty % 3 == 1){
            m++;
            *srodek2 = m + 1;
        }
        else{
            swap(tab[m], tab[p]);
            p--;
        }
    }

}

void menu() {
    int nr;
    int *liczbaStudentow = new int;
    student *tab;
    int* srodek = new int;
    int* srodek2 = new int;

    wczytajStudentow(tab, liczbaStudentow);
    cout<<"Lista przed sortowaniem:"<<endl;
    wyswietlStudentow(tab, *liczbaStudentow);
    cout << "Podaj numer zadania:" << endl << "1 - zad.4.2" << endl << "2 - zad.4.3" << endl;
    cin >> nr;

    switch (nr) {
        case 1:
            cout<<"Wybrano zadanie 4.2 (podzial zbioru na 2 czesci)"<<endl;
            podzialZbioruNa2(tab, *liczbaStudentow, srodek);
            cout<<"Tablica po sortowaniu:"<<endl;
            for (int i = 0; i < *liczbaStudentow; i++) {
                if (i == 0) cout<<"Studenci ktorzy otrzymali <=10 punktow:"<<endl;
                else if (i == *srodek) cout<<"Studenci ktorzy otrzymali >10 punktow:"<<endl;
                cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << endl;
            }
            break;
        case 2:
            cout<<"Wybrano zadanie 4.3 (podzial zbioru na 3 czesci)"<<endl;
            podzialZbioruNa3(tab, *liczbaStudentow, srodek, srodek2);
            cout<<"Tablica po sortowaniu:"<<endl;
            cout<<"Studenci z wynikiem podzielnym przez 3:"<<endl;
            for (int i = 0; i < *liczbaStudentow; i++){
                if (i == *srodek) cout<<"Studenci z wynikiem podzielnym przez 3, z reszta 1:"<<endl;
                else if (i == *srodek2) cout<<"Studenci z wynikiem podzielnym przez 3, z reszta 2:"<<endl;
                cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << endl;
            }
            break;
        default:
            cout<<"Bledny numer"<<endl;
    }
    usunTabliceStudentow(tab);
    delete srodek;
    delete srodek2;
}
