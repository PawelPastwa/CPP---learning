#include "iostream"
#include "zlab06.h"

using namespace std;

int main() {
    Kwadrat k1;
    Kwadrat k2("Drugi kwadrat", 4);
    cout << k1.doTekstu() << endl << endl;
    cout << k2.doTekstu() << endl << endl;

    Kwadrat kwadrat("Kwadrek", 4);
    Prostokat prostokat("Prostak", 2, 4);

    Prostokat *wskaznikDoProstokat;

    wskaznikDoProstokat = &prostokat;
    cout << wskaznikDoProstokat->doTekstu()
         << endl << endl;

    wskaznikDoProstokat = &kwadrat;
    cout << wskaznikDoProstokat->doTekstu()
         << endl << endl;

    Prostokat &referencjaDoProstokat1 = prostokat;

    cout << referencjaDoProstokat1.doTekstu()
         << endl << endl;

    Prostokat &referencjaDoProstokat2 = kwadrat;

    cout << referencjaDoProstokat2.doTekstu()
         << endl << endl;



    Kwadrat &refDoKwadrat = kwadrat;

    double r0 = refDoKwadrat.promienKolaWgPola();
    double r1 = refDoKwadrat.promienOkreguWgObwodu();

    cout << "ro=" << r0 << endl
         << "r1=" << r1 << endl;

    return 0;
}
