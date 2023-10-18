// Dan Collins
// Project Two
// CS-210
// 30 September 2023 

#ifndef INVESTMENT_CALCULATOR_H_
#define INVESTMENT_CALCULATOR_H_

#include <iostream>
#include <iomanip>
using namespace std;

class InvestmentCalculator { //class that calculates and displays info
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_interestRate;
    int m_numberOfYears;

public:
    InvestmentCalculator(); //constructor

    double calculateBalanceWithoutMonthlyDeposit();
    double balanceWithMonthlyDeposit();
    static void printDetails(int t_year, double t_balance, double t_interest);
};

#endif // INVESTMENT_CALCULATOR_H_
