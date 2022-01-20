#pragma once
#include "AmericanOption.h"
#include <vector>

class AmericanCallOption :
    public AmericanOption
{
public:
    AmericanCallOption(double, double);
    virtual double payoff(double& other);
    virtual OptionType GetOptionType();


};

