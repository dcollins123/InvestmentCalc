#include "InvestmentCalculator.h"

InvestmentCalculator::InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears)
    : m_initialInvestment(t_initialInvestment), m_monthlyDeposit(t_monthlyDeposit), m_interestRate(t_interestRate), m_numberOfYears(t_numberOfYears) {} //implements constructor

double InvestmentCalculator::calculateMonthlyInterestRate() const {
    return m_interestRate / 100 / 12;
}

double InvestmentCalculator::calculateBalanceWithoutMonthlyDeposit() { //input data w/o monthly deposits
    double currentBalance = m_initialInvestment;
    double monthlyInterestRate = calculateMonthlyInterestRate();

    for (int i = 1; i <= m_numberOfYears; i++) {
        double yearStartBalance = currentBalance;
        for (int month = 1; month <= 12; month++) {
            currentBalance += (currentBalance * monthlyInterestRate);
        }
        double interestEarnedThisYear = currentBalance - yearStartBalance;
        printDetails(i, currentBalance, interestEarnedThisYear);
    }
    return currentBalance;
}

double InvestmentCalculator::balanceWithMonthlyDeposit() { //input data with monthly deposits
    double currentBalance = m_initialInvestment;
    double monthlyInterestRate = calculateMonthlyInterestRate();

    for (int i = 1; i <= m_numberOfYears; i++) {
        double yearStartBalance = currentBalance;
        for (int month = 1; month <= 12; month++) {
            currentBalance += m_monthlyDeposit;
            currentBalance += (currentBalance * monthlyInterestRate);
        }
        double interestEarnedThisYear = currentBalance - yearStartBalance - (12 * m_monthlyDeposit);
        printDetails(i, currentBalance, interestEarnedThisYear);
    }
    return currentBalance;
}

void InvestmentCalculator::printDetails(int t_year, double t_balance, double t_interest) { //display results
    cout << t_year << "\t\t" << fixed << setprecision(2) << t_balance << "\t\t" << t_interest << endl;
}
