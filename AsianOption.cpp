#include "AsianOption.h"

//When building an asian option, we first need to create an option 
//with the expiry equal to the last date in our time steps vector
AsianOption::AsianOption(std::vector<double> TimeSteps) : Option(TimeSteps[TimeSteps.size() - 1]) 
{
	_TimeSteps = TimeSteps;
}

std::vector<double> AsianOption::GetTimeSteps()
{
	return _TimeSteps;
}


double AsianOption::payoffPath(std::vector<double> v) //V is a spot prices vector
{
	double z = 0;
	double m = v.size();
	for (int i = 0; i < m; i++)
	{
		z = z + v[i];
		std::cout << "v[i] : " << v[i] << std::endl;
	}
	z = (z / m); // We have the mean of the spot prices
	return payoff(z); // We finally return the payoff of the mean of the spot prices
}

bool AsianOption::isAsianOption()
{
	throw true;
}