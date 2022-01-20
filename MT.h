#pragma once
#include <random>
#include <memory>

class MT
{
public:

	//For the copy constructor and the assignment operator, "= delete" 
	//to prevent the compiler to use the default version of the method
	MT(const MT&) = delete;
	MT& operator=(const MT&) = delete;

	//method to get the unique instance of this class
	//returns a reference precisely because we deleted the copy constructor
	//the object is only created if we request it elsewhere 
	//by using the following method
	static MT& getInstance();

	std::mt19937 getMT19937();
	static double rand_unif();
	static double rand_norm();


private:
	//In a singleton, the constructor is located in the private part therefore 
	//we can only access it within the class.

	MT();
	std::mt19937 MT_gen;
};