#pragma once
#include "Option.h"
class DigitalOption :public Option
{
public:
	DigitalOption(double, double);
	~DigitalOption();
	double GetDigitalStrike();
	double GetExpiry();
	friend class BlackScholesPricer;

private:
	double _digitalstrike;
};

