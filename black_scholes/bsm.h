#ifndef __BSM__
#define __BSM__

#include <iostream>

// Black Scholes Model
class BSM {
public:
    BSM(float, float, float, float, float, long, long);
    
    ~BSM();
    
    float getBsmAsset();
    float getBsmStrike();
    float getBsmGrowth();
    float getBsmVol();
    float getBsmYears();
    long  getBsmSteps();
    long  getBsmMonteCarloSims();
    
    void logNormalRandomWalk();
    
    double getCallPrice();
    double getPutPrice();
    
    // generate random numbers
    double rn();

private:

    float bsmAsset;             // underlying asset price
    float bsmStrike;            // strike price on option
    float bsmGrowth;            // risk-free growth rate of the market
    float bsmVol;               // volatility of the asset
    float bsmYears;             // years to maturity
    long  bsmSteps;             // how many steps? daily by default
    long  bsmMonteCarloSims;    // Monte Carlo simulation

    double bsmCallPrice;
    double bsmPutPrice;
};

#endif /* defined(__BSM__) */