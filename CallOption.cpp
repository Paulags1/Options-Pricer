#include "CallOption.h"

CallOption::CallOption(double expiry, double strike) : VanillaOption(expiry, strike)
{

}

CallOption::~CallOption()
{}

double CallOption::payoff(double& z) //Z le prix du sous jacent
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

OptionType CallOption::GetOptionType()
{
	return OptionType::Call;
}

std::string CallOption::TypeOfOption()
{
	return "Call";
}