#include <iostream>
#include "bondDuration.h"

using namespace std;

// constructor
BondDuration::BondDuration(double prin,
                           double coup,
                           double mkt,
                           double yTM,
                           char typ) : Bond(prin, coup, mkt, yTM, typ) {
    cout << "In the DurationBond constructor" << endl;
    
    setDuration( calculateDuration() );
}

// deconstructor
BondDuration::~BondDuration() {
    cout << "Byebye BondDuration" << endl;
}

// calculate the duration of a bond
// idea and intuition:
// higher interest rate -> lower bond price
// lower interest rate -> higher bond price
// duration reflects the sensitivity of the bond price to the change of interest rate
// higher duration means higher sensitivity
double BondDuration::calculateDuration(){
    
    // Get the current market return of the bond
    double origMarketRate = getMarketRate();
    cout << "origMarketRate: " << origMarketRate << endl;
    
    // Shock interest rate factor is 'Y', and 
    // as a difference between rates, we often call it a 'Delta'
    double deltaY = DURATION_BOND_RATE_CHANGE;
    if(origMarketRate <= DURATION_BOND_RATE_CHANGE) {
        deltaY = origMarketRate - 0.0001;
    }
    cout << "deltaY: " << deltaY << endl;
    
    // v1 is the CURRENT bond price
    double v1 = getBondPrice();
    cout << "Current bond price, v1: " << v1 << endl;
    
    // Shock the interest rate down by deltaY
    double bipsLower = origMarketRate - deltaY;
    cout << "bipsLower: " << bipsLower << endl;
    setMarketRate(bipsLower);
    
    // v2 is the HIGHER bound price given a lower interest rate
    double v2 = getBondPrice();
    cout << "Higher bond price, v2: " << v2 << endl;
    
    // Shock the interest rate up by deltaY
    double bipsHigher = origMarketRate + deltaY;
    cout << "bipsHigher: " << bipsHigher << endl;
    setMarketRate(bipsHigher);
    
    // v3 is the LOWER bond price given a higher interest rate
    double v3 = getBondPrice();
    cout << "Lower bond price, v3: " << v3 << endl;
    
    // Reset YTM to actual current rate
    setMarketRate(origMarketRate);
    
    // Calculate the Bond duration
    // Duration = V2 - V3 / 2(V1)(DeltaY)
    double calcDuration = (v2 - v3)/(2 * v1 * deltaY);
    cout << "Internal, calcDuration: " << calcDuration << endl;
    
    return calcDuration;
}

double BondDuration::getDuration() {
    return duration;
}

void BondDuration::setDuration(double inpDurn) {
    duration = inpDurn;
}