#pragma once
#include "DigitalOption.h"
class DigitalPutOption :
	public DigitalOption
{
public:
	DigitalPutOption(double, double);
	~DigitalPutOption();
	virtual double payoff(double& other);
	virtual OptionType GetOptionType();
};

