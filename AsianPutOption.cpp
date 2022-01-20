#include "AsianPutOption.h"
AsianPutOption::AsianPutOption(std::vector<double> TimeSteps, double strike) : AsianOption(TimeSteps)
{
	if (strike > 0)
	{
		_strike = strike;
	}
	else
	{
		_strike = 0;
	}
}

double AsianPutOption::payoff(double& z) //Z est le sous jacent
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

OptionType AsianPutOption::GetOptionType()
{
	return OptionType::Put;
}

double AsianPutOption::GetStrike()
{
	return _strike;
}