#include "Option.h"

Option::Option(double expiry)
{
	if (expiry > 0) { _expiry = expiry; }
	else
	{
		_expiry = 0;
	}
}

Option::~Option()
{ }

double Option::GetExpiry()
{
	return _expiry;
}

bool Option::isAsianOption()
{
	return false;
}

bool Option::isAmericanOption()
{
	return false;
}


double Option::payoffPath(std::vector<double> spot_prices)//vecteur de spot price
{
	return payoff(spot_prices[spot_prices.size() - 1]);
}
