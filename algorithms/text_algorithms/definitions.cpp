#include "prototypy.h"
#include <iostream>
using namespace std;

string wczytajTekst(){

    string tekst;

    cout<<"Podaj tekst: "<<endl;
    getline(cin, tekst);

    return tekst;
}

string wczytajWzorzec(){

    string tekst;

    cout<<"Podaj wzorzec: "<<endl;
    getline(cin, tekst);
    return tekst;
}

void algorytmNaiwny(string a, string b){

    int dl_tekst = a.length();
    int dl_wzorzec = b.length();
    int i = 0;

    while (i <= dl_tekst - dl_wzorzec){
        int j = 0;
        while ((j < dl_wzorzec) && (b[j] == a[i + j])){
            j++;
            if (j == dl_wzorzec) cout<<i<<endl;
        }
        i++;
    }
}

void Knuth(string a, string b){
    int dl_tekst = b.length();
    int dl_wzorzec = a.length();

    int tab_dop[dl_wzorzec + 1];
    tab_dop[0] = 0;
    tab_dop[1] = 0;
    int t = 0;
    int i = 1;

    while (i < dl_wzorzec){
        while (t > 0 && a[t] != a[i])
            t = tab_dop[t];
        if (a[t] == a[i])
            t++;
        tab_dop[i+1] = t;
        i++;
    }

    i = 0;
    int j = 0;

    while (i < dl_tekst - dl_wzorzec + 1){
        while (a[j] == b[i+j] && j < dl_wzorzec)
            j++;
        if (j == dl_wzorzec)
            cout<<i<<endl;
        i += max(1, j-tab_dop[j]);
        j = tab_dop[j];
    }
}

void Boyer(string a, string b, char q, char z) {
    int dl_tekst = b.length();
    int dl_wzorzec = a.length();
    int n_pocz = (int)q;
    int n_kon = (int)z;
    int tab_p[n_kon-n_pocz];

    for (int i = 0; i <= n_kon-n_pocz; i++)
        tab_p[i] = -1;
    for (int i = 0; i < dl_wzorzec; i++)
        tab_p[a[i] - n_pocz] = i;

    int i = 0;

    while (i <= dl_tekst - dl_wzorzec){
        int j = dl_wzorzec - 1;
        while (j > -1 && a[j] == b[i+j])
            j--;
        if (j == -1){
            cout<<i<<endl;
            i++;
        } else
            i = i + max(1, j-tab_p[b[i+j] - n_pocz]);
    }

}

void menu(){
    int nr = 1;
    string tekst = wczytajTekst();
    string wzorzec = wczytajWzorzec();

    while(nr){
        cout<<"Podaj nr zadania"<<endl<<"1 - Algorytm naiwny"<<endl<<"2 - Algorytm KMP"<<endl<<"3 - Algorytm Boyer'a"<<endl<<"0 - wyjscie z programu"<<endl;
        cin >> nr;
        if (nr == 1)
            algorytmNaiwny(tekst, wzorzec);
        if (nr == 2)
            Knuth(wzorzec, tekst);
        if (nr == 3) {
            char a, b;
            cout << "Podaj poczatek alfabetu" << endl;
            cin >> a;
            cout<<"Podaj koniec alfabetu"<<endl;
            cin >> b;
            Boyer(wzorzec, tekst, a, b);
        }
    }
}
