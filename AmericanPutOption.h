#pragma once
#include <vector>
#include "AmericanOption.h"
class AmericanPutOption :
    public AmericanOption
{
public:
    AmericanPutOption(double, double);
    virtual double payoff(double& other);
    virtual OptionType GetOptionType();

};

