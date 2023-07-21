#ifndef HelloWorld_globals_h
#define HelloWorld_globals_h

const int gMonthsInYear = 12;
const int gPercentDenominator = 100;

struct gAmortizeMonth
{
    int year;
    int yearMonth;
    long loanMonth;
    double payment;
    double pureInterest;
    double paidDownPrincipal;
    double principalBalance;
};

#endif