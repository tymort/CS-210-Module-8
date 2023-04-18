/*
Project Two
Tyler Mort
3-29-23
CS 210
 */
#include <iostream>
#include <iomanip>
#include <string>
#include "Calculations.h"

using namespace std;


//Method to calculate and display without deposits
void Calculations::dataWithoutDeposits(UserData t_userInvestment) {
	// Initializing local variables using UserData object
	double initialInvestment = t_userInvestment.getInitialInvestment();
	int years = t_userInvestment.getNumYears();

	cout << endl;

	// Main header for table 
	cout << "\t\t" << "Balance and Interest Without Additional Monthly Deposits" << "\t\t" << endl;
	// For loop to add line breaks for formatting
	for (int i = 0; i < 80; i++) { cout << "="; };
	cout << endl;
	cout << "Year" << "\t\t" << "Year End Balance" << "\t\t" << "Year End Earned Interest" << endl;
	// For loop to add line breaks for formatting
	for (int i = 0; i < 80; i++) { cout << "-"; };
	cout << endl;
	
	// Adds the initial investment to the total investment
	t_userInvestment.setTotalWithoutDeposits(initialInvestment);
	//Initialize year to date interest to 0
	double interestYTD = 0;

	//Declare counter variables for loop for easier readability
	int yearCount;
	int monthCount;

	// Calculates and prints the yearly interest
	for (yearCount = 1; yearCount <= years; yearCount++) {
		//Calculates and sums monthly interest to reach yearly interest
		for (monthCount = 1; monthCount <= 12; monthCount++) {
			interestYTD += t_userInvestment.calculateInterestWithoutDeposits();
		}
		//Adds YTD interest to the balance
		t_userInvestment.setTotalWithoutDeposits(interestYTD);
		//Outputs data in table format
		cout << yearCount << "\t\t";
		cout << "$" << fixed << setprecision(2) << t_userInvestment.getTotalWithoutDeposits();
		cout << "\t\t\t\t" << "$" << fixed << setprecision(2) << interestYTD << endl;

		//Resets interest to 0
		interestYTD = 0;
	}
}
//Method to calculate and display with deposits
void Calculations::dataWithDeposits(UserData t_userInvestment) {
	// Initializing local variables using UserData object
	double initialInvestment = t_userInvestment.getInitialInvestment();
	double monthlyDeposit = t_userInvestment.getMonthlyDeposit();
	int years = t_userInvestment.getNumYears();

	cout << endl;

	// Main header for table
	cout << "\t\t" << "Balance and Interest With Additional Monthly Deposits" << "\t\t" << endl;
	// For loop to add line breaks for formatting
	for (int i = 0; i < 80; i++) { cout << "="; };
	cout << endl;
	cout << "Year" << "\t\t" << "Year End Balance" << "\t\t" << "Year End Earned Interest" << endl;
	// For loop to add line breaks for formatting
	for (int i = 0; i < 80; i++) { cout << "-"; };
	cout << endl;

	// Adds the initial investment to the total investment
	t_userInvestment.setTotalWithDeposits(initialInvestment);
	//Initialize year to date interest to 0
	double interestYTD = 0;

	//Declare counter variables for loop for easier readability
	int yearCount;
	int monthCount;

	// Calculates and prints the yearly interest
	for (yearCount = 1; yearCount <= years; yearCount++) {
		//Calculates and sums monthly interest to reach yearly interest
		for (monthCount = 1; monthCount <= 12; monthCount++) {
			//Adds monthly deposit each month before finding interest
			t_userInvestment.setTotalWithDeposits(monthlyDeposit);			
			double interest = t_userInvestment.calculateInterestWithDeposits();
			//Adds interest to balance
			t_userInvestment.setTotalWithDeposits(interest);				
			interestYTD += interest;
		}
		//Outputs data in table format
		cout << yearCount << "\t\t";
		cout << "$" << fixed << setprecision(2) << t_userInvestment.getTotalWithDeposits();
		cout << "\t\t\t\t" << "$" << fixed << setprecision(2) << interestYTD << endl;

		//Resets interest to 0
		interestYTD = 0;
	}
}
