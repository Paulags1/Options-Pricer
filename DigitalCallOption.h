#pragma once
#include "DigitalOption.h"
class DigitalCallOption :
	public DigitalOption
{
public:
	DigitalCallOption(double, double);
	~DigitalCallOption();
	virtual double payoff(double& other);
	virtual OptionType GetOptionType();
};

