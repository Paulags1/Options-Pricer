#include "AmericanPutOption.h"
#include <vector>

AmericanPutOption::AmericanPutOption(double strike, double expiry) : AmericanOption(strike, expiry)
{

}

double AmericanPutOption::payoff(double& z) //Z est le sous jacent
{
	if (z <= GetStrike())
	{
		return GetStrike() - z;
	}
	else
	{
		return 0;
	}
}



OptionType AmericanPutOption::GetOptionType()
{
	return OptionType::Put;
}