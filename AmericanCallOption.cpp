#include "AmericanCallOption.h"
#include <iostream>

AmericanCallOption::AmericanCallOption(double strike, double expiry) : AmericanOption(strike, expiry)
{

}

double AmericanCallOption::payoff(double& z) //Z le prix du sous jacent
{
	if (z >= GetStrike())
	{
		return z - GetStrike();
	}
	else
	{
		return 0;
	}
}


OptionType AmericanCallOption::GetOptionType()
{
	return OptionType::Call;
}