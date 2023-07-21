#ifndef __BondDuration__
#define __BondDuration__

#include <iostream>
#include "bond.h"

using namespace std;

// inherits the class Bond
// focus on the duration of a bond
class BondDuration : public Bond {

public:
    
    const double DURATION_BOND_RATE_CHANGE = 0.005;
    
    BondDuration(double, double, double, double, char);
    
    ~BondDuration();
    
    double calculateDuration();
    
    void setDuration(double);
    
    double getDuration();
    
private:
    
    double duration;
    
};

#endif /* defined(__DurationBond__) */