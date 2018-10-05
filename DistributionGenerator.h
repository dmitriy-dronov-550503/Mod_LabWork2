#pragma once
#include <iostream>

#include "LehmerRand.h"

using namespace std;

class DistributionGenerator
{
private:
	LehmerRand lr;

public:
	DistributionGenerator();
	~DistributionGenerator();

	double Uniform(double a, double b);
	double Gaussian(double m, double sigma);
	double Exponencial(double lambda);
	double Gamma(double nu, double lambda);
	double Triangle_Up(double a, double b);
	double Triangle_Down(double a, double b);
	double Simpsons(double a, double b);
};

