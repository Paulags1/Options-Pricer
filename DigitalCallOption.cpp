#include "DigitalCallOption.h"

DigitalCallOption::DigitalCallOption(double expiry, double strike) : DigitalOption(expiry, strike)
{

}

DigitalCallOption::~DigitalCallOption()
{}

double DigitalCallOption::payoff(double& z) //Z le prix du sous jacent
{
	if (z >= GetDigitalStrike())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

OptionType DigitalCallOption::GetOptionType()
{
	return OptionType::Call;
}