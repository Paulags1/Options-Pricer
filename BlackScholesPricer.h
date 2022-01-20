#pragma once
#include "VanillaOption.h"
#include "DigitalOption.h"
#include "Option.h"
#include <ctime>

class BlackScholesPricer
{

public:
	BlackScholesPricer(VanillaOption* option, double asset_price, double interest_rate, double volatility);
	BlackScholesPricer(DigitalOption* option, double asset_price, double interest_rate, double volatility);
	BlackScholesPricer();
	BlackScholesPricer(const BlackScholesPricer& other);
	OptionType GetOptionType();
	double GetAssetPrice() const;
	double GetInterestRate() const;
	double GetVolatility() const;
	double operator()();
	double digitaloperator();
	double delta(const BlackScholesPricer&);
	friend VanillaOption;
	double digitaldelta(const BlackScholesPricer&);
	friend DigitalOption;


private:
	VanillaOption* _option;
	DigitalOption* _digitaloption;
	double _asset_price;
	double _interest_rate;
	double _volatility;
};

