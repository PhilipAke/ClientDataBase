#include <iostream>
#include "Services.h"
using namespace std;
void Clients::returnToMenu() {
    string menuChoice1;
    cout << "Please Select what you would like to do:" << endl;
    cout << "1) Client Info" << endl;
    cout << "2) Sales Reps" << endl;
    cout << "3) Products/Services" << endl;
    cout << "4) Sales" << endl;
    cout << "5) Quit";
    while ("5" != menuChoice1) {
        cin >> menuChoice1;
        if (menuChoice1 == "1") {
            Clients m;
            m.clientInfoMenu();
        } else if (menuChoice1 == "2") {
            SalesRep s;
            s.salesRepMenu();
        } else if (menuChoice1 == "3") {
            Services s;
            s.servicesMenu();
        } else if (menuChoice1 == "4") {
            Sales s;
            s.salesMenu();
        } else if (menuChoice1 == "5") {
            cout << "Goodbye (:";
        } else {
            cout << "Invalid Input Please Try Again." << endl;
            returnToMenu();
        }
    }
}
int main() {
    Clients m;
    m.returnToMenu();
    return 0;
}
