#include "BlackScholesPricer.h"
#include <math.h>
#include <cmath>

BlackScholesPricer::BlackScholesPricer(VanillaOption* option, double asset_price, double interest_rate, double volatility)
{
	_option = option;
	_asset_price = asset_price;
	_interest_rate = interest_rate;
	_volatility = volatility;
}


BlackScholesPricer::BlackScholesPricer(DigitalOption* option, double asset_price, double interest_rate, double volatility)
{
	_digitaloption = option;
	_asset_price = asset_price;
	_interest_rate = interest_rate;
	_volatility = volatility;
}


BlackScholesPricer::BlackScholesPricer()
{
	_option = NULL;
	_asset_price = 0;
	_interest_rate = 0;
	_volatility = 0;
}
BlackScholesPricer::BlackScholesPricer(const BlackScholesPricer& other)
{
	_option = other._option;
	_asset_price = other._asset_price;
	_interest_rate = other._interest_rate;
	_volatility = other._volatility;

}

double BlackScholesPricer::GetAssetPrice() const
{
	return _asset_price;
}

double BlackScholesPricer::GetInterestRate() const
{
	return _interest_rate;
}

double BlackScholesPricer::GetVolatility() const
{
	return _volatility;
}


double BlackScholesPricer::operator()()
{
	double K;
	K = _option->GetStrike();
	double T;
	T = _option->GetExpiry();
	double P;
	P = 0;
	double S0;
	S0 = _asset_price;
	double r;
	r = _interest_rate;
	double v;
	v = _volatility;
	double d1;
	d1 = (1 / (v * sqrt(T))) * (log(S0 / K) + (r + 0.5 * v * v) * T);
	double d2;
	d2 = d1 - v * sqrt(T);

	if (_option->GetOptionType() == Call)
	{
		double Nd1;
		Nd1 = 0.5 * (1 + std::erf(d1 / sqrt(2)));
		double Nd2;
		Nd2 = 0.5 * (1 + std::erf(d2 / sqrt(2)));
		P = S0 * Nd1 - K * Nd2 * exp(-r * T);
	}
	if (_option->GetOptionType() == Put)
	{
		double Nd1;
		Nd1 = 0.5 * (1 + std::erf(-d1 / sqrt(2)));
		double Nd2;
		Nd2 = 0.5 * (1 + std::erf(-d2 / sqrt(2)));
		P = -S0 * Nd1 + K * Nd2 * exp(-r * T);
	}
	return P;
}

double BlackScholesPricer::delta(const BlackScholesPricer& other)
{
	double delta;
	double T;
	T = _option->GetExpiry();
	double K;
	K = _option->GetStrike();
	double P;
	P = 0;
	double S0;
	S0 = _asset_price;
	double r;
	r = _interest_rate;
	double v;
	v = _volatility;
	double d1;
	d1 = (1 / (v * sqrt(T))) * (log(S0 / K) + (r + 0.5 * v * v) * T);
	double Nd1;
	Nd1 = 0.5 * (1 + std::erfc(d1 / sqrt(2)));
	delta = Nd1 - 1;
	return delta;
}

double BlackScholesPricer::digitaldelta(const BlackScholesPricer& other)
{
	return 0;
}

double BlackScholesPricer::digitaloperator()
{
	double T;
	T = _digitaloption->GetExpiry();
	double K;
	K = _digitaloption->GetDigitalStrike();
	double P;
	P = 0;
	double S0;
	S0 = _asset_price;
	double r;
	r = _interest_rate;
	double v;
	v = _volatility;
	if (_digitaloption->GetOptionType() == Call)
	{
		P = (log(K) - log(S0) - (r - 0.5 * v * v) * T) / (v * sqrt(T));
	}
	if (_digitaloption->GetOptionType() == Put)
	{
		P = (log(K) - log(S0) - (r - 0.5 * v * v) * T) / (v * sqrt(T));
	}
	return P;
}