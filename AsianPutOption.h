#pragma once
#include "AsianOption.h"
class AsianPutOption :
    public AsianOption
{
public:
    AsianPutOption(std::vector<double>, double);
    virtual double payoff(double& other);
    OptionType GetOptionType();
    double GetStrike();
private:
    double _strike;
};

