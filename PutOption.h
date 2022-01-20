#pragma once
#include "VanillaOption.h"
class PutOption : public VanillaOption
{
public:
	PutOption(double, double);
	~PutOption();
	double payoff(double& other);
	virtual OptionType GetOptionType();
};

