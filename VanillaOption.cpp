#include "VanillaOption.h"
#include <typeinfo>

VanillaOption::VanillaOption(double expiry, double strike) : Option(expiry)
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

VanillaOption::~VanillaOption()
{}

double VanillaOption::GetStrike()
{
	return _strike;
}

double VanillaOption::GetExpiry()
{
	return Option::GetExpiry();
}
