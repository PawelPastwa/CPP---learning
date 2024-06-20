#include <iostream>

using namespace std;

enum typ {
    rosnaco, malejaco
};

void przydzielPamiec1D(int *&tab, int n);

void wypelnijTablice1D(int *tab, int n, int a, int b);

void wyswietl1D(int *tab, int n);

void usunTablice1D(int *&tab);

void przydzielPamiec2D(int **&tab, int w, int k);

void wypelnijTablice2D(int **tab, int w, int k, int a, int b);

void wyswietl2D(int **tab, int w, int k);

void usunTablice2D(int **&tab, int w);

void sortowanieBabelkowe(int *tab, int n, typ tryb, int a, int b);

void sortowaniePrzezWybor(int *tab, int n, typ tryb, int a, int b);

void sortowaniePrzezWstawianie(int *tab, int n, int tryb, int a, int b);

void sortowanie2D(int **tab, int w, int k, typ tryb, int nrKol, int a, int b);

void menu();

int main() {

    menu();


    return 0;
}


void przydzielPamiec1D(int *&tab, int n) {
    tab = new int[n];
}

void wypelnijTablice1D(int *tab, int n, int a, int b) {
    for (int i = 0; i < n; i++)
        tab[i] = rand() % (b - a + 1) + a;
}

void wyswietl1D(int *tab, int n) {
    for (int i = 0; i < n; ++i)
        cout << "wartosc " << i << " elementu tablicy to: " << tab[i] << endl;
}

void usunTablice1D(int *&tab) {
    delete[] tab;
}

void przydzielPamiec2D(int **&tab, int w, int k) {
    tab = new int *[w];

    for (int i = 0; i < w; i++)
        tab[i] = new int[k];
}

void wypelnijTablice2D(int **tab, int w, int k, int a, int b) {
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            tab[i][j] = rand() % (b - a + 1) + a;
}

void wyswietl2D(int **tab, int w, int k) {
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < k; ++j)
            cout << tab[i][j] << "\t";
        cout << "" << endl;
    }
}

void usunTablice2D(int **&tab, int w) {
    for (int i = 0; i < w; ++i)
        delete[] tab[i];

    delete[] tab;
}

void sortowanieBabelkowe(int *tab, int n, typ tryb, int a, int b) {

    przydzielPamiec1D(tab, n);

    wypelnijTablice1D(tab, n, a, b);
    cout << "Tablica przed sortowaniem:" << endl;
    wyswietl1D(tab, n);

    if (tryb == malejaco) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++)
                if (tab[i] > tab[j])
                    swap(tab[i], tab[j]);
    } else if (tryb == rosnaco) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++)
                if (tab[i] < tab[j])
                    swap(tab[i], tab[j]);
    }
    cout << "Tablica po sortowaniu:" << endl;
    wyswietl1D(tab, n);
    usunTablice1D(tab);
}

void sortowaniePrzezWybor(int *tab, int n, typ tryb, int a, int b) {

    przydzielPamiec1D(tab, n);
    wypelnijTablice1D(tab, n, a, b);
    cout << "Tablica przed sortowaniem:" << endl;
    wyswietl1D(tab, n);

    for (int i = 0; i < n - 2; i++) {
        int min = tab[i];
        int k;
        if (tryb == rosnaco) {
            for (int j = i + 1; j < n - 1; j++) {
                if (tab[j] < min) {
                    min = tab[j];
                    k = j;
                }
            }
            if (min < tab[i]) swap(tab[i], tab[k]);
        } else if (tryb == malejaco) {
            for (int j = i + 1; j < n; j++) {
                if (tab[j] > min) {
                    min = tab[j];
                    k = j;
                }
            }
            if (min > tab[i]) swap(tab[i], tab[k]);
        }
    }
    cout << "Tablica po sortowaniu:" << endl;
    wyswietl1D(tab, n);
    usunTablice1D(tab);
}

void sortowaniePrzezWstawianie(int *tab, int n, int tryb, int a, int b) {

    przydzielPamiec1D(tab, n);
    wypelnijTablice1D(tab, n, a, b);
    cout << "Tablica przed posortowaniem" << endl;
    wyswietl1D(tab, n);

    if (tryb == rosnaco) {
        for (int i = 1; i < n; i++) {
            int j;
            j = i;
            while (tab[j - 1] > tab[j] && j > 0) {
                swap(tab[j - 1], tab[j]);
                j--;
            }
        }
    }
    if (tryb == malejaco) {
        for (int i = 1; i < n; i++) {
            int j;
            j = i;
            while (tab[j - 1] < tab[j] && j > 0) {
                swap(tab[j - 1], tab[j]);
                j--;
            }
        }
    }
    cout << "Tablica po posortowaniu:" << endl;
    wyswietl1D(tab, n);
    usunTablice1D(tab);
}

void sortowanie2D(int **tab, int w, int k, typ tryb, int nrKol, int a, int b) {

    przydzielPamiec2D(tab, w, k);
    wypelnijTablice2D(tab, w, k, a, b);
    cout << "Tablica przed sortowaniem:" << endl;
    wyswietl2D(tab, w, k);

    int *tab1;

    przydzielPamiec1D(tab1, w);

    for (int i = 0; i < w; i++) {
        tab1[i] = tab[i][nrKol];
    }

    if (tryb == rosnaco) {
        for (int i = 1; i < w; i++) {
            int j;
            j = i;
            while (tab1[j - 1] > tab1[j] && j > 0) {
                swap(tab1[j - 1], tab1[j]);
                swap(tab[j - 1], tab[j]);
                j--;
            }

        }
    }
    if (tryb == malejaco) {
        for (int i = 1; i < w; i++) {
            int j;
            j = i;
            while (tab1[j - 1] < tab1[j] && j > 0) {
                swap(tab1[j - 1], tab1[j]);
                swap(tab[j - 1], tab[j]);
                j--;
            }
        }
    }

    usunTablice1D(tab1);

    cout << "Tablica po sortowaniu:" << endl;
    wyswietl2D(tab, w, k);
    usunTablice2D(tab, w);

}

void menu() {

    int jak;
    int lewa, prawa;

    cout << "Podaj typ sortowaia (0 - rosnaco, 1 - malejaco): " << endl;
    cin >> jak;
    cout << "Podaj min granice losowanych liczb: " << endl;
    cin >> lewa;
    cout << "Podaj max granice losowanych liczb: " << endl;
    cin >> prawa;

    typ sortowanie = static_cast<typ>(jak);

    int nr = 1;

    while (nr){
    cout << "Podaj numer zadania lub wpisz 0 by zakonczyc program:" << endl;
    cout << "1 - zad. 2.2 (bubblesort)" << endl << "2 - zad.2.3 (selectionsort)" << endl << "3 - zad.2.4 (insertosrt)"
         << endl << "4 - zad.2.5 (sortowanie tab 2D)" << endl;
    cin >> nr;

    switch (nr) {
        case 1:
            int *tab1;
            int ile;

            cout << "Wybrano zad 2.2 (bubblesort)" << endl;
            cout << "Podaj ilosc elementow tablicy" << endl;
            cin >> ile;

            sortowanieBabelkowe(tab1, ile, sortowanie, lewa, prawa);

            break;
        case 2:
            int *tab2;
            int ile2;

            cout << "Wybrano zad 2.3 (selectsort)" << endl;
            cout << "Podaj ilosc elementow tablicy" << endl;
            cin >> ile2;

            sortowaniePrzezWybor(tab2, ile2, sortowanie, lewa, prawa);

            break;
        case 3:
            int *tab3;
            int ile3;

            cout << "Podaj dlugosc tablicy" << endl;
            cin >> ile3;

            sortowaniePrzezWstawianie(tab3, ile3, sortowanie, lewa, prawa);

            break;
        case 4:
            int **tab4;
            int rzedy;
            int kolumny;
            int kol;

            cout << "Wybrano zad 2.5 (sortowanie tab 2D selectionsort)" << endl;
            cout << "Podaj ilosc rzedow" << endl;
            cin >> rzedy;
            cout << "Podaj ilosc kolumn" << endl;
            cin >> kolumny;
            cout << "Podaj nr kolumny wzgledem ktorej tablica bedzie posortowana:" << endl;
            cin >> kol;

            sortowanie2D(tab4, rzedy, kolumny, sortowanie, kol, lewa, prawa);

            break;

        default:
            break;
    }
    }

}
