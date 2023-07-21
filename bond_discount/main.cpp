#include <iostream>
#include "bond.h"
#include "bondDuration.h"

using namespace std;

int main(int argc, const char * argv[]) {
    /* 
    // normal bond
    Bond complexBond(7000, 0.07, 0.05, 12, 'S');
    
    double externalBondPrice = complexBond.getBondPrice();
    
    cout << "externalBondPrice: " <<
            externalBondPrice << endl;
    
    return 0;
    */

    // duration bond
    BondDuration db(1000, 0.07, 0.08, 10, 'S');
    
    double dbPrice = db.getBondPrice();
    
    cout << "dbPrice: " << dbPrice << endl;
    
    double dbDuration = db.getDuration();
    
    cout << "dbDuration: " << dbDuration << endl;
    
    return 0;
}