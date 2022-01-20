#pragma once
#include "Option.h"
#include <vector>

class AmericanOption : public Option
{
public:
	AmericanOption(double, double);
	double GetExpiry();
	double GetStrike();
	bool isAmericanOption();


private:
	double _strike;
};

