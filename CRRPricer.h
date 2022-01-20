#pragma once
#include "Option.h"
#include "BinaryTree.h"
#include "AsianOption.h"
#include "AmericanOption.h"
#include "VanillaOption.h"
#include "DigitalOption.h"
#include <ctime>
#include <functional>
class CRRPricer
{
public:
	CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
	CRRPricer(AsianOption* option, int depth, double asset_price, double up, double down, double interest_rate);
	CRRPricer(AmericanOption* option, int depth, double asset_price, double up, double down, double interest_rate);
	CRRPricer(Option* option, int depth, double asset_price, double r, double volatility);
	CRRPricer();
	//CRRPricer(const CRRPricer& other);
	Option option() const;
	double GetAssetPrice() const;
	double GetInterestRate() const;
	int GetDepth() const;
	double GetUp() const;
	double GetDown() const;
	BinaryTree<double> GetSimPrices() const;
	BinaryTree<double> GetSimCalls() const;
	BinaryTree<bool> GetExerciseCondition() const;
	void compute();
	double operator()(bool = false);
	double GetH(int n, int i) const;
	double Factorial(double k);

	bool getExercise(int, int);

private:
	Option* _option;
	double _asset_price;
	double _interest_rate;
	int _depth;
	double _up;
	double _down;
	BinaryTree<double> _s_prices; //Tree of the simulated stock prices
	BinaryTree<double> _c_prices; //Tree of the simulated call prices
	BinaryTree<bool> _exercise_condition; //Tree of the simulated call prices
};



