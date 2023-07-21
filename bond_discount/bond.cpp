#include "bond.h"
#include <iostream>
#include <cmath>

using namespace std;

// A straightforward constructor
// parameters: principal, couponRate, marketRate, yearsToMaturity, paymentType
Bond::Bond(double prin, double coup, double mkt, double yTM, char typ) {
    // if the paymentType does not match any of the three predefined types
    // the bond is invalid
    if ((typ != BOND_ANNUAL_TYPE) &&
        (typ != BOND_SEMIANNUAL_TYPE) &&
        (typ != BOND_QUARTERLY_TYPE)) {
        throw BOND_INVALID_BOND_TYPE;
    }
    
    cout << "Got here, after bond type check!" << endl;
    
    setPrincipal(prin);
    setCouponRate(coup);
    setMarketRate(mkt);
    setYearsToMaturity(yTM);
    setPaymentType(typ);
}

Bond::~Bond() {
    cout << "Byebye Bond" << endl;
}

// Pricing the bond given necessary parameters
double Bond::getBondPrice() {
    double bondPrice = 0.0;
    
    // initialize payment frequency per year
    int frequency = 0;
    
    // the scaling factor is determined by payment type
    if(getPaymentType() == BOND_ANNUAL_TYPE) {
        frequency = 1;
    }
    else if (getPaymentType() == BOND_SEMIANNUAL_TYPE) {
        frequency = 2;
    }
    else if (getPaymentType() == BOND_QUARTERLY_TYPE) {
        frequency = 4;
    }
    
    // coupon = face_value * coupon_rate / frequency
    double coupon =
        getPrincipal() * (getCouponRate()/frequency);    
    cout << "Coupon: " << coupon << endl;
    
    // periods = years * frequency per year
    double periods =
        getYearsToMaturity() * frequency;
    cout << "Periods: " << periods << endl;
    
    // yield to maturity = market required rate = market rate / frequency
    double yield = getMarketRate()/frequency;
    cout << "Yield: " << yield << endl;
    
    // cash flow discount for periodic coupon payments
    // O  ---C---C---C---C---C---C---C---C........
    //    <---
    //    <-------
    //    <-----------
    // + XXX
    double pvCoupons =
        (coupon * (1 - pow((1 + yield), -periods)))/yield; 
    cout << "PV of Coupons: " << pvCoupons << endl;
    
    // cash flow discount for principal at maturity
    // O  ---|---|---|---|---|---|---|---P
    //    <-------------------------------
    // = XXX
    double pvRedemption =
        getPrincipal() * pow((1 + yield), -periods);
    cout << "PV of Redemption: " << pvRedemption << endl;
    
    // internal bond price = discounted coupon + principal redemption
    bondPrice = pvCoupons + pvRedemption;
    cout << "Internal bond price: " << bondPrice << endl;
    
    return bondPrice;
}

void Bond::setPrincipal(double prin) {
    principal = prin;
}

double Bond::getPrincipal() {
    return principal;
}

void Bond::setCouponRate(double rat) {   
    couponRate = rat;
}

double Bond::getCouponRate() {
    return couponRate;
}

void Bond::setMarketRate(double rat) {
    marketRate = rat;
}

double Bond::getMarketRate()
{
    return marketRate;
}

void Bond::setYearsToMaturity(double yTM) {
    yearsToMaturity = yTM;
}

double Bond::getYearsToMaturity() {
    return yearsToMaturity;
}

void Bond::setPaymentType(char type) {
    paymentType = type;
}

char Bond::getPaymentType() {
    return paymentType;
}