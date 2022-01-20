#include "AsianCallOption.h"

AsianCallOption::AsianCallOption(std::vector<double> TimeSteps,double strike) : AsianOption(TimeSteps)
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

double AsianCallOption::payoff(double& z) //Z le prix du sous jacent
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

OptionType AsianCallOption::GetOptionType()
{
	return OptionType::Call;
}

double AsianCallOption::GetStrike()
{
	return _strike;
}