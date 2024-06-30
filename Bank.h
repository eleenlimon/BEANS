#pragma once 
// Ensures that this header file is included only once in the compilation process

#ifndef BANK_H // Header guard to prevent multiple inclusions of the header file
#define BANK_H

// Bank class declaration
class Bank {
public:
  // Setter methods
  void SetInitialInvestment(double absInitialInvestment);
  void SetMonthlyDeposit(double absMonthlyDeposit);
  void SetInterestRate(double absAnnualInterest);
  void SetNumberOfYears(int absNumberOfYears);

  // Getter methods
  double GetInitialInvestment() const;
  double GetMonthlyDeposit() const;
  double GetInterestRate() const;
  int GetNumberOfYears() const;

  // Calculation methods
  double calculateBalanceWithoutMonthlyDeposit(double absInitialInvestment, double absAnnualInterest, int absNumberOfYears);
  double balanceWithMonthlyDeposit(double absInitialInvestment, double absMonthlyDeposit, double absAnnualInterest, int absNumberOfYears);

private:
  // Private member variables
  double totalAmount;
  double interest_Amount;
  double yearly_TotalInterest;
  double monthly_Deposit;
  double number_OfYears;
};

// Declare global variables for simplicity
extern Bank myInvestment;
extern double initialInvestment;
extern double monthlyDeposit;
extern double annualInterest;
extern int years;
extern char user_input;

#endif // End of BANK_H and header guard