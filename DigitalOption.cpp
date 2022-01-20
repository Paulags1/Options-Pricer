#include "DigitalOption.h"
DigitalOption::DigitalOption(double expiry, double strike) : Option(expiry)
{
	if (strike > 0)
	{
		_digitalstrike = strike;
	}
	else
	{
		_digitalstrike = 0;
	}
}

DigitalOption::~DigitalOption()
{}

double DigitalOption::GetDigitalStrike()
{
	return _digitalstrike;
}

double DigitalOption::GetExpiry()
{
	return Option::GetExpiry();
}