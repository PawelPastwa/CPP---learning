#include <iostream>
#include <math.h>

using namespace std;

void przydzielPamiec1D(int *&tab, int n);
void przydzielPamiec2D(int **&tab, int w, int k);
void wypelnijTablice1D(int *tab, int n, int a, int b);
void wypelnijTablice2D(int **tab, int w, int k, int a, int b);
void usunTablice1D(int *&tab);
void usunTablice2D(int **&tab, int w);
void wyswietl1D(int* tab, int n);
void wyswietl2D(int** tab, int w, int k);

void menu();
void zad_1_2(int *&tab, int n, int a, int b);
void zad_1_3(int *&tab, int n);
void zad_1_4(int **&tab, int w, int k, int a, int b);
void zad_1_5(int **&tab, int n);

int main()
{
    menu();
    return 0;
}

void przydzielPamiec1D(int *&tab, int n)
{
    tab = new int[n];
}

void przydzielPamiec2D(int **&tab, int w, int k)
{
    tab = new int*[w];

    for(int i = 0; i < w; i++)
        tab[i] = new int[k];
}

void wypelnijTablice1D(int *tab, int n, int a, int b)
{
    for (int i = 0; i < n; i++)
        tab[i] = rand() % (b - a + 1) + a;
}

void wypelnijTablice2D(int **tab, int w, int k, int a, int b)
{
    for(int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            tab[i][j] = rand () % (b-a+1) + a;
}

void usunTablice1D(int *&tab)
{
    delete [] tab;
}

void usunTablice2D(int **&tab, int w)
{
    for (int i = 0; i < w; ++i)
        delete [] tab[i];

    delete [] tab;
}

void wyswietl1D(int *tab, int n)
{
    for (int i = 0; i < n; ++i)
        cout << "wartosc "<<i<<" elementu tablicy to: " << tab[i] <<endl;
}

void wyswietl2D(int **tab, int w, int k)
{
    for (int i = 0; i < w; ++i)
        for (int j = 0; j < k; ++j)
            cout << "Wartosc elementu "<<i<<" "<<j<<" tablicy wynosi: " <<tab[i][j] << endl;
}

void zad_1_2(int *&tab, int n, int a, int b)
{
    bool czypierwsza = false;
    int min;
    przydzielPamiec1D(tab, n);
    for (int i = 0; i < n; ++i)
    {
        tab[i] = rand () % (b - a + 1) + a;
        if (i == 0) min = tab[i];
        else
            if (tab[i] < min) min = tab[i];
    }
    for (int i = 2; i <= sqrt(min); i++)
    {
        if (min % i == 0)
            czypierwsza = false;
        else
            czypierwsza = true;
    }
    wyswietl1D(tab, n);
    if (czypierwsza == true)
        cout << "Liczba: "<<min<<" jest najmniejsza w tej tablicy i jest liczba pierwsza"<<endl;
    else
        cout << "Liczba: "<<min<<" jest najmniejsza w tej tablicy i nie jest liczba pierwsza"<<endl;
    delete [] tab;
}

void zad_1_3(int *&tab, int n)
{
    przydzielPamiec1D(tab, n);

    int licznik0 = 0, licznik1 = 0, licznik2 = 0, licznik3 = 0, licznik4 = 0, licznik5 = 0, licznik6 = 0, licznik7 = 0, licznik8 = 0, licznik9 = 0;

    for (int i = 0; i < n; i++)
    {
        tab[i] = rand() % 10;
        switch (tab[i])
        {
            case 0:
                licznik0++;
                break;
            case 1:
                licznik1++;
                break;
            case 2:
                licznik2++;
                break;
            case 3:
                licznik3++;
                break;
            case 4:
                licznik4++;
                break;
            case 5:
                licznik5++;
                break;
            case 6:
                licznik6++;
                break;
            case 7:
                licznik7++;
                break;
            case 8:
                licznik8++;
                break;
            case 9:
                licznik9++;
                break;
            default:
                cout << "Cos poszlo nie tak..." <<endl;
                break;
        }
    }
    wyswietl1D(tab, n);
    cout << "Cyfra 0 wystapila: "<<licznik0<< " razy"<<endl<<"Cyfra 1 wystapila: "<<licznik1<<" razy"<<endl<<"Cyfra 2 wystapila: "<<licznik2<<" razy"<<endl<<"Cyfra 3 wystapila: "<<licznik3<<" razy"<<endl<<"Cyfra 4 wystapila: "<<licznik4<<" razy"<<endl<<"Cyfra 5 wystapila: "<<licznik5<<" razy"<<endl<<"Cyfra 6 wystapila: "<<licznik6<<" razy"<<endl<<"Cyfra 7 wystapila: "<<licznik7<<" razy"<<endl<<"Cyfra 8 wystapila: "<<licznik8<<" razy"<<endl<<"Cyfra 9 wystapila: "<<licznik9<<" razy"<<endl;
    usunTablice1D(tab);
}

void zad_1_4(int **&tab, int w, int k, int a, int b)
{
    przydzielPamiec2D(tab, w, k);

    int max = 0;

    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
        {
            tab[i][j] = rand() % (b - a + 1) + a;
            if (tab[i][j] > max) max = tab[i][j];
        }

    string licznik = to_string(max);
    int ile_cyfr = licznik.length();

    int sumaCyfr = 0;
    int max2 = max;
    for (int i = 1; i <= ile_cyfr; i++)
    {
        sumaCyfr += (max2 % (int)pow(10, i)) / pow(10, i - 1);
        max2 -= max2 % (int)pow(10, i);
    }

    wyswietl2D(tab, w, k);
    cout << "Najwieksza liczba w tej tablicy to: "<<max<<endl<<"A suma jej cyfr to: "<<sumaCyfr<<endl;

    usunTablice2D(tab, w);
}

void zad_1_5(int **&tab, int n)
{
    przydzielPamiec2D(tab, n, n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tab[i][j] = rand() % (116) + 7;

    int sumanad = 0, sumapod = 0, liczniknad = 0, licznikpod = 0;
    float srednianad, sredniapod;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            sumanad += tab[i][j];
            liczniknad++;
        }

    for (int i = (n-2); i >= 0; i--)
        for (int j = (n-1); j > i; j--)
        {
            sumapod += tab[i][j];
            licznikpod++;
        }

    srednianad = (float)sumanad/liczniknad;
    sredniapod = (float)sumapod/licznikpod;
    wyswietl2D(tab, n, n);
    cout << "Srednia liczb nad glowna przekatna wynosi: "<<srednianad<<endl<<"A srednia pod glowna przekatna wynosi: "<<sredniapod<<endl;

    usunTablice2D(tab, n);
}

void menu()
{
    int wybor;

    cout << "Wybierz zadanie:"<<endl<<"Zad.1.2 - 1"<<endl<<"Zad.1.3 - 2"<<endl<<"Zad.1.4 - 3"<<endl<<"Zad.1.5 - 4"<<endl<<"Wyjscie z programu - 0"<<endl;
    cin >> wybor;

    switch (wybor)
    {
        case 0:
            break;
        case 1:
            int *tab1D, n, a, b;
            cout << "Podaj dlugosc tablicy:"<<endl;
            cin >> n;
            cout << "Podaj lewa granice:"<<endl;
            cin >> a;
            cout << "Podaj prawa granice:"<<endl;
            cin >> b;
            zad_1_2(tab1D, n, a, b);
            break;
        case 2:
            int *tab1D_1, g;
            cout << "Podaj dlugosc tablicy:"<<endl;
            cin >> g;
            zad_1_3(tab1D_1, g);
            break;
        case 3:
            int **tab2D, w, k, p, o;
            cout << "Podaj ilosc kolumn tablicy:"<<endl;
            cin >> w;
            cout << "Podaj ilosc rzedow tablicy:"<<endl;
            cin >> k;
            cout << "Podaj lewa granice:"<<endl;
            cin >> p;
            cout << "Podaj prawa granice:"<<endl;
            cin >> o;
            zad_1_4(tab2D, w, k, p, o);
            break;
        case 4:
            int **tab2D_1, n_1;
            cout << "Podaj bok kwadratowej tablicy:"<<endl;
            cin >> n_1;
            zad_1_5(tab2D_1, n_1);
            break;
        default:
            cout << "Podano niewlasciwa cyfre" <<endl;
    }
}
