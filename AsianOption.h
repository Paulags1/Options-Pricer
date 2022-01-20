#pragma once
#include "Option.h"
#include <vector>

class AsianOption :public Option
{
public:
	AsianOption(std::vector<double>);
	std::vector<double> GetTimeSteps();
	double payoffPath(std::vector<double>);
	bool isAsianOption();

private:
	std::vector<double> _TimeSteps;
};

