#pragma once
#include "VanillaOption.h"
class CallOption : public VanillaOption
{
public:
	CallOption(double, double);
	~CallOption();
	double payoff(double& other);
	virtual OptionType GetOptionType();
	std::string TypeOfOption();
};

