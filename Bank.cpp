#include "Bank.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Define global variables
Bank myInvestment;
double initialInvestment;
double monthlyDeposit;
double annualInterest;
int years;
char user_input;

// Setters
void Bank::SetInitialInvestment(double absInitialInvestment) {
    totalAmount = absInitialInvestment;
}

void Bank::SetMonthlyDeposit(double absMonthlyDeposit) {
    monthly_Deposit = absMonthlyDeposit;
}

void Bank::SetInterestRate(double absAnnualInterest) {
    yearly_TotalInterest = absAnnualInterest;
}

void Bank::SetNumberOfYears(int absNumberOfYears) {
    number_OfYears = absNumberOfYears;
}

// Getters
double Bank::GetInitialInvestment() const {
    return totalAmount;
}

double Bank::GetMonthlyDeposit() const {
    return monthly_Deposit;
}

double Bank::GetInterestRate() const {
    return yearly_TotalInterest;
}

int Bank::GetNumberOfYears() const {
    return number_OfYears;
}

// Calculate balance without monthly deposit
double Bank::calculateBalanceWithoutMonthlyDeposit(double absInitialInvestment, double absAnnualInterest, int absNumberOfYears) {
    // Initialize total amount with the initial investment
    totalAmount = absInitialInvestment;

    // Output header for calcuations
    cout << endl << "     Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << std::string(66, '=') << endl;
    cout << "Year     Year End Balance     Year End Earned Interest" << endl;
    cout << std::string(66, '-') << endl;

    // Calculate and display balance and interest for each year
    for (int i = 0; i < absNumberOfYears; i++) {
        // Calculate interest earned for the current year
        interest_Amount = totalAmount * (absAnnualInterest / 100);

        //Output the year, year end balance, and earned interest
        totalAmount = totalAmount + interest_Amount;
        cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t\t$" << interest_Amount << endl;
    }

    // Return the final total amount after all years
    return totalAmount;
}

// Calculate balance with monthly deposit
double Bank::balanceWithMonthlyDeposit(double absInitialInvestment, double absMonthlyDeposit, double absAnnualInterest, int absNumberOfYears) {
    totalAmount = absInitialInvestment;

    // Output header
    cout << endl << "     Balance and Interest With Additional Monthly Deposits" << endl;
    cout << std::string(66, '=') << endl;
    cout << "Year     Year End Balance     Year End Earned Interest" << endl;
    cout << std::string(66, '-') << endl;

    // Calculate and display balance and interest for each year
    for (int i = 0; i < absNumberOfYears; i++) {
        yearly_TotalInterest = 0;

        // Calculate interest and update total amount for each month
        for (int j = 0; j < 12; j++) {
            // Calculate monthly interest
            interest_Amount = (totalAmount + absMonthlyDeposit) * ((absAnnualInterest / 100.00) / 12.00);

            // Accumulate monthly interest to yearly total interest
            yearly_TotalInterest = yearly_TotalInterest + interest_Amount;

            // Update total amount by adding monthly deposit and interest earned
            totalAmount = totalAmount + absMonthlyDeposit + interest_Amount;
        }

        // Output year, year-end balance, and earned interest
        cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t\t$" << yearly_TotalInterest << endl;
    }

    // Return the final total amount after all years
    return totalAmount;
}