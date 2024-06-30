#include "Menu.h"  // Include the Menu header file
#include "Bank.h"  // Include the Bank header file
#include <iostream>  // Include the standard input/output stream header file
#include <stdexcept>  // Include the header file for standard exceptions

using namespace std;  // Use the standard namespace


// Function to display the main menu screen and get input from the user
void mainMenu() {
  try {
    // Displaying the main menu header
    cout << std::string(34, '*') << endl;
    cout << std::string(10, '*') << " Data Input " << std::string(12, '*') << endl;

    // Getting initial investment amount from user
    cout << "Initial Investment Amount: $";
    initialInvestment = validDoubleInput();
    if (initialInvestment < 0) {
      throw runtime_error("Invalid entry.");
    }
    myInvestment.SetInitialInvestment(initialInvestment);

    // Getting monthly deposit from user
    cout << "Monthly Deposit: $";
    monthlyDeposit = validDoubleInput();
    if (monthlyDeposit < 0) {
      throw runtime_error("Invalid entry.");
    }
    myInvestment.SetMonthlyDeposit(monthlyDeposit);

    // Getting annual interest rate from user
    cout << "Annual Interest: %";
    annualInterest = validDoubleInput();;
    if (annualInterest < 0) {
      throw runtime_error("Invalid entry.");
    }
    myInvestment.SetInterestRate(annualInterest);

    // Getting number of years from user
    cout << "Number of years: ";
    years = validIntInput();
    if (years <= 0) {
      throw runtime_error("Invalid entry.");
    }
    myInvestment.SetNumberOfYears(years);

    // Perform and print the calculations
    myInvestment.calculateBalanceWithoutMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());
    myInvestment.balanceWithMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetMonthlyDeposit(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());
  }

  // Catching any runtime errors and displaying error message
  catch (runtime_error& excpt) {
    cout << excpt.what() << endl;
    cout << "Cannot compute with negative value." << endl;
    // Display main menu again if there's an error
    Menu();
  }
}

// User input validation to ensure input is an integer
int validIntInput() {
  int x;

  // Loop until valid input is received
  while (1) {
    if (cin >> x) {
      // Valid number
      break;
    }
    else {
      // Invalid number
      cout << "Invalid Input. Please input a numerical value.";
      cin.clear();
      // Discard invalid input
      while (cin.get() != '\n');    // Clearing input buffer
    }
  }

  return x;
}

// User input validation to ensure input is a double
double validDoubleInput() {
  double x;

  // Loop until valid input is received
  while (1) {
    if (cin >> x) {
      // Valid number
      break;
    }
    else {
      // Invalid number
      cout << "Invalid Input. Please enter valid number: ";
      cin.clear();
      // Discard invalid input
      while (cin.get() != '\n');    // Clearing input buffer
    }
  }

  return x;
}

// Main menu function to handle user input and display results
void Menu() {
    user_input = 'a';

    // Continue showing menu until user chooses to quit
    while (user_input != 'q') {
        
      // Display the main menu and get user inputs
        mainMenu();

        // Ask user if they want to quit or continue
        cout << "Press 'q' to quit. Press any other key to continue. ";
        cin >> user_input;
    }
}