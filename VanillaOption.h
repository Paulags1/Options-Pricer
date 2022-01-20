#pragma once
#include "Option.h"
class VanillaOption :public Option
{
public:

	VanillaOption(double, double);
	~VanillaOption();
	double GetStrike();
	double GetExpiry();

private:
	double _strike;
};

