#pragma once
#ifndef AIRGEADBANKING_UserData_H_
#define AIRGEADBANKING_UserData_H_
#endif

// UserData class
class UserData {
//Public classes
public: 
	//Setter methods
	void setInitialInvestment(double t_initialInvestment);
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setAnnualInterest(double t_annualInterest);
	void setNumYears(int t_years);
	void setTotalWithDeposits(double t_amount);
	void setTotalWithoutDeposits(double t_amount);

	//Getter methods
	double getInitialInvestment() { return m_initialInvestment; }
	double getMonthlyDeposit() { return m_monthlyDeposit; }
	double getAnnualInterest() { return m_annualInterest; }
	int getNumYears() { return m_numYears; }
	double getTotalWithDeposits();
	double getTotalWithoutDeposits();

	//Calculation methods
	double calculateInterestWithDeposits();
	double calculateInterestWithoutDeposits();

//Private variables with leading member identifier
private: 
	double m_initialInvestment = 0.0;
	double m_monthlyDeposit = 0.0;
	double m_annualInterest = 0.0;
	int m_numYears = 0;
	double m_totalWithDeposits = 0.0;
	double m_totalWithoutDeposits = 0.0;

};