#include "BlackScholesMCPricer.h"
#include <math.h>  
#include "AsianOption.h"


BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility)
{
	_option = option;
	_initial_price = initial_price;
	_interest_rate = interest_rate;
	_volatility = volatility;
}

BlackScholesMCPricer::~BlackScholesMCPricer()
{

}

int BlackScholesMCPricer::getNbPaths() const
{
	return NbPaths;
}

void BlackScholesMCPricer::generate(int nb_paths)
{
	//Vector where we will store the spot prices generated with the Wiener process starting with S0
	std::vector<double> spot_paths;
	double spot_t;
	double z;
	double payoffs = 0;
	// m : Number of periods for which we simulate the price of the underlying asset
	double new_price_estimate = 0;


	int m = 0;
	std::vector<double> timesteps;
	
	estimates_mean = 0; //Variable used to compute the mean of the computed option prices
	estimates_variance = 0; //Variable used to compute the variance of the computed option prices


	if (_option->isAsianOption())
	{
		m = ((AsianOption*)_option)->GetTimeSteps().size();
	}
	else //For both Vanilla and Digital options because they are European options
	{
		 m = 1;
	}
	double T = _option->GetExpiry(); //Option expiry date

	double deltaT = T / m;
	for (int t = 0; t <= m; t++)
	{
		timesteps.push_back(t * deltaT);
	}

	//i represents the number of the sequence of prices that is currently simulated
	for (int i = 0; i < nb_paths; i++)
	{

		spot_paths.push_back(_initial_price);
		//k represents the time of the spot price that is currently simulated
		for (int k = 0; k < m; k++)
		{

			//Initialize Z a gaussian centered and reduced random variable using our singleton class
			z = MT::rand_norm();

			//Generate a spot price with the Wiener process formula at time k + 1 and add it to the vector of simulated spot prices
			spot_t = spot_paths[k] * exp((_interest_rate - (_volatility * _volatility) / 2) * (timesteps[k + 1] - timesteps[k]) + _volatility * sqrt(timesteps[k + 1] - timesteps[k]) * z);
			spot_paths.push_back(spot_t);
		}

		payoffs = _option->payoffPath(spot_paths) + payoffs; //Compute the sum of the payoffs of the simulated sequence
		
		//Reset the spot prices vector
		spot_paths.clear();

	}

	//Computation of the option price
	new_price_estimate = exp(-_interest_rate * T) * (1 / double(nb_paths)) * payoffs; //H0


	estimates_mean = new_price_estimate * double(nb_paths) + estimates_mean;
	estimates_variance = pow(new_price_estimate * double(nb_paths), 2) + estimates_variance;

	_price_estimate = (_price_estimate * NbPaths + new_price_estimate * nb_paths) / double(NbPaths + nb_paths);


	estimated_prices.push_back(new_price_estimate);


	////Computation of the mean of the estimated prices
	//for (size_t j = 0; j < estimated_prices.size(); j++)
	//{
	//	estimates_mean = estimates_mean + estimated_prices[j];
	//}
	//estimates_mean = estimates_mean / nb_paths;

	////Computation of the variance of the estimated prices
	//for (size_t j = 0; j < estimated_prices.size(); j++)
	//{
	//	estimates_variance = estimates_variance + (estimated_prices[j] - estimates_mean) * (estimated_prices[j] - estimates_mean);
	//}
	//estimates_variance = estimates_variance / nb_paths;

	////std::cout << "Current estimate : " << _price_estimate << std::endl;
	////std::cout << "Current estimate MEAN : " << estimates_mean << std::endl;

	//for (auto& price : estimated_prices)
	//{
	//	std::cout << "simulations : " << price << " ";
	//}

	//std::cout << std::endl;

	NbPaths = nb_paths + NbPaths;
}

double BlackScholesMCPricer::operator()()
{
	try
	{
		if (NbPaths == 0)
		{
			throw std::string("No Monte Carlo generation has been called previously.");
		}

		return _price_estimate;
	}
	catch (const std::string& e)
	{
		std::cerr << e << std::endl;
	}
}

std::vector<double> BlackScholesMCPricer::confidenceInterval()
{
	std::vector<double> CI;

	double upper_bound, lower_bound;

	lower_bound = estimates_mean - 1.96 * (sqrt(1 / double(NbPaths) * estimates_variance - pow(1 / double(NbPaths) * estimates_mean, 2) / NbPaths));
	upper_bound = estimates_mean + 1.96 * (sqrt(1 / double(NbPaths) * estimates_variance - pow(1 / double(NbPaths) * estimates_mean, 2) / NbPaths));
	CI = { lower_bound, upper_bound };
	return CI;
}