#pragma once
#include "Option.h"
#include "MT.h"


class BlackScholesMCPricer
{
public:
	BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility);
	~BlackScholesMCPricer();
	double operator()();

	void generate(int nb_paths);
	std::vector<double> confidenceInterval();

	int getNbPaths() const;

private:
	Option* _option;
	double _initial_price;
	double _interest_rate;
	double _volatility;
	double _price_estimate; //Option price
	double estimates_mean;
	double estimates_variance;

	int NbPaths; //Number of paths generated since the begginning of the program

	std::vector<double> estimated_prices; //Vector to store the computed option prices
};

