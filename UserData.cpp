/*
Project Two
Tyler Mort
3-29-23
CS 210
 */
#include <iostream>
#include "UserData.h"
using namespace std;

//Setter Methods
//Sets the initial investment amount
void UserData::setInitialInvestment(double t_initialInvestment) { 
	m_initialInvestment = t_initialInvestment;
}
//Sets the monthly deposit amount
void UserData::setMonthlyDeposit(double t_monthlyDeposit) { 
	m_monthlyDeposit = t_monthlyDeposit;
}
//Sets the annual interest amount
void UserData::setAnnualInterest(double t_annualInterest) {
	m_annualInterest = t_annualInterest;
}
//Sets the number of years
void UserData::setNumYears(int t_numYears) {
	m_numYears = t_numYears;
}
//Sets the current total for the account without deposits
void UserData::setTotalWithoutDeposits(double t_amount) {
	m_totalWithoutDeposits += t_amount;
}
//Sets the current total for the account with deposits
void UserData::setTotalWithDeposits(double t_amount) {
	m_totalWithDeposits += t_amount;
}

//Getter Methods
//Gets the current total for the account without deposits
double UserData::getTotalWithoutDeposits() { // gets total without deposits
	return m_totalWithoutDeposits;
}
//Gets the current total for the account with deposits
double UserData::getTotalWithDeposits() { // gets total with deposits
	return m_totalWithDeposits;
}

//Calculation methods
//Calculates interest for the account without deposits
double UserData::calculateInterestWithoutDeposits() { // calculates interest without deposits
	return ((m_totalWithoutDeposits) * ((m_annualInterest / 100) / 12));
}
//Calculates interest for the account with deposits
double UserData::calculateInterestWithDeposits() { // calculates interest with deposits
	return ((m_totalWithDeposits) * ((m_annualInterest / 100) / 12));
}