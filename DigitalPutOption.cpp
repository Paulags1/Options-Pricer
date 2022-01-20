#include "DigitalPutOption.h"

DigitalPutOption::DigitalPutOption(double expiry, double strike) : DigitalOption(expiry, strike)
{

}

DigitalPutOption::~DigitalPutOption()
{}

double DigitalPutOption::payoff(double& z) //Z le prix du sous jacent
{
	if (z > GetDigitalStrike())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

OptionType DigitalPutOption::GetOptionType()
{
	return OptionType::Put;
}