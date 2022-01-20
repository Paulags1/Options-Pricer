#include "PutOption.h"


PutOption::PutOption(double expiry, double strike) : VanillaOption(expiry, strike)
{ }

PutOption::~PutOption()
{}

double PutOption::payoff(double& z) //Z est le sous jacent
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

OptionType PutOption::GetOptionType()
{
	return OptionType::Put;
}