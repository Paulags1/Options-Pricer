#include <iostream>
#include "Option.h"
#include "CallOption.h"
#include "PutOption.h"
#include "BlackScholesPricer.h"
#include "CRRPricer.h"
#include "BinaryTree.h"
#include "VanillaOption.h"
#include "DigitalOption.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include "PutOption.h"
#include "AsianOption.h"
#include "AsianCallOption.h"
#include "AsianPutOption.h"
#include "MT.h"
#include "BlackScholesMCPricer.h"
#include "AmericanOption.h"
#include "AmericanCallOption.h"
#include "AmericanPutOption.h"
#include <cmath>
#include <string.h>


int main() {

	double S0(102.), K(100.), T(2), r(0.05), sigma(0.25);
	CallOption opt1(T, K);
	PutOption opt2(T, K);


	std::cout << "European options 1" << std::endl << std::endl;


	BlackScholesPricer pricer1(&opt1, S0, r, sigma);
	std::cout << "Call BlackScholesPricer price=" << pricer1() << ", delta=" << pricer1.delta(pricer1) << std::endl;


	BlackScholesPricer pricer2(&opt2, S0, r, sigma);
	std::cout << "Put BlackScholesPricer price=" << pricer2() << ", delta=" << pricer2.delta(pricer2) << std::endl;
	std::cout << std::endl;

	int N(150);
	double U = exp(sigma * sqrt(T / N)) - 1.0;
	double D = exp(-sigma * sqrt(T / N)) - 1.0;
	double R = exp(r * T / N) - 1.0;

	CRRPricer crr_pricer1(&opt1, N, S0, U, D, R);
	std::cout << "Calling CRR pricer with depth=" << N << std::endl;
	std::cout << std::endl;
	std::cout << "CRR pricer computed price=" << crr_pricer1(false) << std::endl;
	std::cout << "CRR pricer explicit formula price=" << crr_pricer1(true) << std::endl;


	CRRPricer crr_pricer2(&opt2, N, S0, U, D, R);
	std::cout << "Calling CRR pricer with depth=" << N << std::endl;
	std::cout << std::endl;
	std::cout << "CRR pricer computed price=" << crr_pricer2(false) << std::endl;
	std::cout << "CRR pricer explicit formula price=" << crr_pricer2(true) << std::endl;

	std::cout << std::endl << "*********************************************************" << std::endl;

	std::cout << "Binary Tree" << std::endl << std::endl;
	BinaryTree<bool> t1;
	t1.setDepth(3);
	t1.setNode(1, 1, true);
	t1.display();
	t1.setDepth(5);
	t1.display();
	t1.setDepth(3);
	t1.display();


	BinaryTree<double> t2;
	t2.setDepth(2);
	t2.setNode(2, 1, 3.14);
	t2.display();
	t2.setDepth(4);
	t2.display();
	t2.setDepth(3);
	t2.display();

	BinaryTree<int> t3;
	t3.setDepth(4);
	t3.setNode(3, 0, 8);
	t3.display();
	t3.setDepth(2);
	t3.display();
	t3.setDepth(4);
	t3.display();

	std::cout << std::endl << "*********************************************************" << std::endl;


	double S0_digital(95.), K_digital(100.), T_digital(0.5), r_digital(0.02), sigma_digital(0.2);
	DigitalCallOption opt3(T_digital, K_digital);
	DigitalPutOption opt4(T_digital, K_digital);


	std::cout << "European digital options " << std::endl << std::endl;


	BlackScholesPricer pricer3(&opt3, S0_digital, r_digital, sigma_digital);
	std::cout << "BlackScholesPricer price=" << pricer3.digitaloperator() << ", delta=" << pricer3.digitaldelta(pricer3) << std::endl;

	BlackScholesPricer pricer4(&opt4, S0_digital, r_digital, sigma_digital);
	std::cout << "BlackScholesPricer price=" << pricer4.digitaloperator() << ", delta=" << pricer4.digitaldelta(pricer4) << std::endl;
	std::cout << std::endl;

	int N_digital(150);
	double U_digital = exp(sigma_digital * sqrt(T_digital / N_digital)) - 1.0;
	double D_digital = exp(-sigma_digital * sqrt(T_digital / N_digital)) - 1.0;
	double R_digital = exp(r_digital * T_digital / N_digital) - 1.0;

	CRRPricer crr_pricer3(&opt3, N_digital, S0_digital, U_digital, D_digital, R_digital);
	std::cout << "Calling CRR pricer with depth=" << N_digital << std::endl;
	std::cout << std::endl;
	std::cout << "CRR pricer computed price=" << crr_pricer3(false) << std::endl;
	std::cout << "CRR pricer explicit formula price=" << crr_pricer3(true) << std::endl;

	CRRPricer crr_pricer4(&opt4, N_digital, S0_digital, U_digital, D_digital, R_digital);
	std::cout << "Calling CRR pricer with depth=" << N_digital << std::endl;
	std::cout << std::endl;
	std::cout << "CRR pricer computed price=" << crr_pricer4(false) << std::endl;
	std::cout << "CRR pricer explicit formula price=" << crr_pricer4(true) << std::endl;


	std::cout << std::endl << "*********************************************************" << std::endl;


	S0 = 102., K = 100., T = 2, r = 0.05, sigma= 0.25;

	std::cout << "Monte carlo prices" << std::endl;

	std::vector<Option*> opt_ptrs;
	opt_ptrs.push_back(new CallOption(T, K));
	opt_ptrs.push_back(new PutOption(T, K));
	opt_ptrs.push_back(new DigitalCallOption(T, K));
	opt_ptrs.push_back(new DigitalPutOption(T, K));

	std::vector<double> fixing_dates;
	for (int i = 1; i <= 5; i++) {
		fixing_dates.push_back(0.1 * i);
	}
	opt_ptrs.push_back(new AsianCallOption(fixing_dates, K));
	opt_ptrs.push_back(new AsianPutOption(fixing_dates, K));

	std::vector<double> ci;
	BlackScholesMCPricer* pricer5;

	for (auto& opt_ptr : opt_ptrs) {
		pricer5 = new BlackScholesMCPricer(opt_ptr, S0, r, sigma);
		do {
			pricer5->generate(10);
			ci = pricer5->confidenceInterval();
		} while (ci[1] - ci[0] > 1e-2);
		std::cout << "nb samples: " << pricer5->getNbPaths() << std::endl;
		std::cout << "price: " << (*pricer5)() << std::endl << std::endl;
		delete pricer5;
		delete opt_ptr;
	}

	double _S0(95.), _K(100.), _T(0.5), _r(0.02), _sigma(0.2);

	AmericanCallOption opt9(_T,_K);
	CRRPricer crr_pricer9(&opt9, 100, S0, U, D, R);
	std::cout << "Calling CRR pricer with depth=" << N << std::endl;
	std::cout << std::endl;


	std::cout << "CRR pricer computed price for American Call Option =" << crr_pricer9(false) << std::endl;
	std::cout << "CRR pricer explicit formula price for American Call Option=" << crr_pricer9(true) << std::endl;
}
