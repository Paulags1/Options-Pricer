#include "MT.h"
#include <iostream>

MT::MT()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	MT_gen = gen;
}

MT& MT::getInstance()
{
	//As MT is a singleton we can only call it by refering to its adress with getInstance
	static std::unique_ptr<MT> instance(new MT());
	return *instance;
}

std::mt19937 MT::getMT19937()
{
	return MT_gen;
}

//Generates random numbers in the uniform distribution using a singleton
double MT::rand_unif()
{
	std::uniform_real_distribution<double> uniform_pdf(0.0, 1.0);
	return uniform_pdf(getInstance().MT_gen);
}

//Generates random numbers in the random distribution using a singleton
double MT::rand_norm()
{
	std::normal_distribution<> gaussian_pdf(0.0, 1.0);
	return gaussian_pdf(getInstance().MT_gen);
}