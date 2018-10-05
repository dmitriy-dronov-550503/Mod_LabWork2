#include "stdafx.h"
#include "DistributionGenerator.h"
#include <algorithm>

DistributionGenerator::DistributionGenerator()
{
}


DistributionGenerator::~DistributionGenerator()
{
}

double DistributionGenerator::Uniform(double a, double b)
{
	double X = a + (b - a) * lr.Rand();
	return X;
}

double DistributionGenerator::Gaussian(double m, double sigma)
{
	double sum = 0;

	for (int i = 0; i < 6; i++)
	{
		sum += lr.Rand();
	}

	double X = m + (sigma * sqrt(2) * (sum - 3));

	return X;
}

double DistributionGenerator::Exponencial(double lambda)
{
	double X = (-1 / lambda) * log(lr.Rand());

	return X;
}

double DistributionGenerator::Gamma(double nu, double lambda)
{
	double comp = lr.Rand();

	for (int i = 0; i < nu - 1; i++)
	{
		comp *= lr.Rand();
	}

	double X = (-1 / lambda) * log(comp);

	return X;
}

double DistributionGenerator::Triangle_Up(double a, double b)
{
	double X = a + (b - a) * min(lr.Rand(), lr.Rand());

	return X;
}

double DistributionGenerator::Triangle_Down(double a, double b)
{
	double X = a + (b - a) * max(lr.Rand(), lr.Rand());

	return X;
}

double DistributionGenerator::Simpsons(double a, double b)
{
	double y = Uniform(a / 2, b / 2);
	double z = Uniform(a / 2, b / 2);
	double X = y + z;

	return X;
}
