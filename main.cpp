#include "InvestmentCalculator.h"

int main() {
    cout << "Welcome to the investment calculator!" << endl;

    double initialInvestment, monthlyDeposit, interestRate;
    int numberOfYears;

    //Menu loop
    while (true) {
        cout << "Please choose an option: " << endl;
        cout << "1. Calculate balance without monthly deposit" << endl;
        cout << "2. Calculate balance with monthly deposit" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            // User input
            try {
                cout << "Enter initial investment amount: ";
                cin >> initialInvestment;
                if (cin.fail()) throw runtime_error("Invalid input for investment amount.");

                cout << "Enter annual interest rate (e.g. for 3.5% interest, enter 3.5): ";
                cin >> interestRate;
                if (cin.fail()) throw runtime_error("Invalid input for interest rate.");

                cout << "Enter number of years: ";
                cin >> numberOfYears;
                if (cin.fail() || numberOfYears < 0) throw runtime_error("Invalid input for number of years.");

                InvestmentCalculator calc(initialInvestment, 0.0, interestRate, numberOfYears);
                cout << "Results: " << endl;
                calc.calculateBalanceWithoutMonthlyDeposit();

            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;

        case 2:
            // User input 
            try {
                cout << "Enter initial investment amount: ";
                cin >> initialInvestment;
                if (cin.fail()) throw runtime_error("Invalid input for investment amount.");

                cout << "Enter monthly deposit amount: ";
                cin >> monthlyDeposit;
                if (cin.fail()) throw runtime_error("Invalid input for monthly deposit.");

                cout << "Enter annual interest rate (e.g. for 3.5% interest, enter 3.5): ";
                cin >> interestRate;
                if (cin.fail()) throw runtime_error("Invalid input for interest rate.");

                cout << "Enter number of years: ";
                cin >> numberOfYears;
                if (cin.fail() || numberOfYears < 0) throw runtime_error("Invalid input for number of years.");

                InvestmentCalculator calc(initialInvestment, monthlyDeposit, interestRate, numberOfYears);
                cout << "Results: " << endl;
                calc.balanceWithMonthlyDeposit();

            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;

        case 3:
            exit(0);

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
    return 0;
}

