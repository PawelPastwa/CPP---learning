#ifndef LAB_2_PD_ZLAB12_H
#define LAB_2_PD_ZLAB12_H
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class ZLab12 {
public:
    void strumienTekstowy();
    void zapisTekstowyDoPliku(std::string nazwaPliku);
    void odczytPlikuTekstowego(std::string nazwaPliku);
    void zapisBinarnyDoPliku(std::string nazwaPliku);
    void odczytPlikuBinarnego(std::string nazwaPliku);

};


#endif //LAB_2_PD_ZLAB12_H
