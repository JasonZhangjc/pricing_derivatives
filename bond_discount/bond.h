#ifndef bond_h
#define bond_h

class Bond {

public:
    
    // Three different payment types
    const char BOND_ANNUAL_TYPE = 'A';
    const char BOND_SEMIANNUAL_TYPE = 'S';
    const char BOND_QUARTERLY_TYPE = 'Q';
    
    const int BOND_INVALID_BOND_TYPE = 99;
    
    // constructor
    Bond(double, double, double, double, char);
    
    // deconstructor
    ~Bond();
    
    double getBondPrice();
    
    void setPrincipal(double);
    
    double getPrincipal();
    
    void setCouponRate(double);
    
    double getCouponRate();
    
    void setMarketRate(double);
    
    double getMarketRate();
    
    void setYearsToMaturity(double);
    
    double getYearsToMaturity();
    
    void setPaymentType(char);
    
    char getPaymentType();
    
private:
    double principal;
    double couponRate;
    double marketRate;
    double yearsToMaturity;
    char paymentType; // 'A'nnual, 'S'emi-Annual, 'Q'uarterly
};

#endif