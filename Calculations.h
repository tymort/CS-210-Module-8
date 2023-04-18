#pragma once
#ifndef AIRGEADBANKING_CALCULATIONS_H_
#define AIRGEADBANKING_CALCULATIONS_H_
#endif 

#include "UserData.h"

// Class to calculate investment information and print as table
class Calculations { 

public:
	void dataWithoutDeposits(UserData t_userInvestment);
	void dataWithDeposits(UserData t_userInvestment);

};