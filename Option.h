#pragma once
#include <iostream>
#include <vector>
enum OptionType { Call, Put };
class Option
{
private:
	double _expiry;

public:
	Option(double expiry);
	~Option();
	virtual double payoff(double& other) = 0;  //Represent function h
	double GetExpiry();
	virtual OptionType GetOptionType() = 0;

	// AsianOption
	double payoffPath(std::vector<double>);
	bool isAsianOption();

	// AmericanOption
	virtual bool isAmericanOption();
};





