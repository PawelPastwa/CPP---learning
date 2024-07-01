#ifndef LAB_2_PD_ZLAB09_H
#define LAB_2_PD_ZLAB09_H
#include <iostream>
#include "osobniki.h"
using namespace std;

class ZLab09 {
public:
    void rozmiary();
    int* wskInt1D = nullptr;
    int** wskInt2D = nullptr;
    void skalar();
    void tablica1D();
    void tablica2D(int w, int k);
    void referencja();

};


#endif //LAB_2_PD_ZLAB09_H
