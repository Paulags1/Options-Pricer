#pragma once
#include "AsianOption.h"
class AsianCallOption :
    public AsianOption
{
public:
    AsianCallOption(std::vector<double>,double);
    virtual double payoff(double& other);
    OptionType GetOptionType();
    double GetStrike();
private:
    double _strike;
};

