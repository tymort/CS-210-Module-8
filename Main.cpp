/*
Project Two
Tyler Mort
3-29-23
CS 210
 */

#include <iostream>
#include <string>
#include "UserData.h"
#include "Calculations.h"
using namespace std;



// Investment function
void investmentInterface() {
	UserData userInvestment; // Creates an object of the UserData class
	Calculations dataCalculations; // Creates an object of the Calculations class

	// User input variables
	double initialAmount;
	double monthlyDeposit;
	double interest; 
	int years;

	string userChoice;	// User input for program continuation
	bool continueLoop = true;	// Flag variable for program continuation

	do {
		for (int i = 0; i < 34; i++) { cout << "*"; };
		cout << endl;
		cout << "*\t" << "  User Data Input" << "\t *" << endl;


		cout << "Initial Investment Amount: $";
		do {
			cin >> initialAmount;
			if (initialAmount < 0) {
				cout << "Please enter a valid value. Accepted values are non-negative balances";
			}
		} while (initialAmount < 0);
		cout << endl;

		cout << "Monthly Deposit: $";
		do {
			cin >> monthlyDeposit;
			if (monthlyDeposit < 0) {
				cout << "Please enter a valid value. Accepted values are non-negative deposits";
			}
		} while (monthlyDeposit < 0);
		cout << endl;

		cout << "Annual Interest: %";
		do {
			cin >> interest;
			if (interest < 0) {
				cout << "Please enter a valid value. Accepted values are non-negative interests";
			}
		} while (interest < 0);
		cout << endl;

		cout << "Number of years: ";
		do {
			cin >> years;
			if (years < 0) {
				cout << "Please enter a valid value. Accepted values are non-negative years";
			}
		} while (years < 0);
		cout << endl;


		// Pass data to userInvestment object and set values
		userInvestment.setInitialInvestment(initialAmount);
		userInvestment.setMonthlyDeposit(monthlyDeposit);
		userInvestment.setAnnualInterest(interest);
		userInvestment.setNumYears(years);

		// Display the user inputted data
		cout << "Initial Investment Amount: " << "\t\t" << "$" << userInvestment.getInitialInvestment() << endl;
		cout << "Monthly Deposit: " << "\t\t\t" << "$" << userInvestment.getMonthlyDeposit() << endl;
		cout << "Annual Interest: " << "\t\t\t" << " " << userInvestment.getAnnualInterest() << "%" << endl;
		cout << "Number of years: " << "\t\t\t" << " " << userInvestment.getNumYears() << endl;

		// Try methods to display calculated data
		try {
			dataCalculations.dataWithoutDeposits(userInvestment);
		}
		catch (const std::exception&) {
			cout << "error occurred with dataWithoutDeposits" << endl;
			continueLoop = false;
		}

		try
		{
			dataCalculations.dataWithDeposits(userInvestment);
		}
		catch (const std::exception&)
		{
			cout << "error occurred with dataWithDeposits" << endl;
			continueLoop = false;
		}

		cout << endl;

		// Ask user if they want to continue loop
		cout << "Would you like to continue?" << endl;
		cout << "Please enter y/n" << endl;
		cin >> userChoice;
		//Convert user choice string to applicable boolean for loop
		if (userChoice == "n") {
			continueLoop = false;
		}
		else {
			continueLoop = true;
		}
	} while (continueLoop == true);

}
// Main Function
int main() {

	try {
		investmentInterface();
	}
	catch (const std::exception&) {
		cout << "error occurred with investmentInterface" << endl;
		return 1;
	}
	return 0;
}

