// Mod_LabWork2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

#include "LehmerRand.h"

using namespace std;

double uniformDistribution(double a, double b, double R)
{
	double X = a + (b - a) * R;
	return X;
}

double gaussianDistribution(double m, double sigma)
{
	double sum = 0;

	static LehmerRand lr;
	for (int i = 0; i < 6; i++)
	{
		sum += lr.Rand();
	}

	double x = m + (sigma * sqrt(2) * (sum - 3));
	
	return x;
}

double exponentDistribution(double lambda, double R)
{
	double X = (-1 / lambda) * log(R);
	
	return X;
}

double gammaDistribution(double nu, double lambda)
{
	static LehmerRand lr;
	double comp = lr.Rand();
	for (int i = 0; i < nu - 1; i++)
	{
		comp *= lr.Rand();
	}

	double X = (-1 / lambda) * log(comp);

	return X;
}

double triangleDistribution(double a, double b, double R1, double R2)
{
	double X = a + (b - a) * max(R1, R2);

	return X;
}

double simpsonsDistribution(double a, double b, double R1, double R2)
{
	double y = uniformDistribution(a / 2, b / 2, R1);
	double z = uniformDistribution(a / 2, b / 2, R2);
	double X = y + z;

	return X;
}

void printHistogram(vector<double> xs, uint32_t histogramSize);
void printHistogram(vector<double> xs, uint32_t histogramSize, double min, double max);

void printHistogram(vector<double> xs, uint32_t histogramSize, double min, double max)
{
	xs.push_back(min);
	xs.push_back(max);
	printHistogram(xs, histogramSize);
}

void printHistogram(vector<double> xs, uint32_t histogramSize = 20)
{
	// Build histogram
	//const uint32_t histogramSize = 10;
	double max = *max_element(xs.begin(), xs.end());
	double min = *min_element(xs.begin(), xs.end());
	double rVal = max - min;
	double delta = rVal / histogramSize;
	//cout << "rVal = " << rVal << " delta = " << delta << endl;
	//cout << "min = " << min << "  max = " << max << endl;
	vector<double> histogramData(histogramSize);


	for (uint32_t j = 0; j < xs.size(); j++)
	{
		for (int i = 0; i < histogramSize; i++)
		{
			double x = xs[j] - min;
			//cout << "x = " << x << " delta * i = " << delta * i << " delta * (i + 1) = " << delta * (i + 1) << endl;
			if ((x >= (delta * i)) && (x <= (delta * (i + 1))))
			{
				histogramData[i]++;
				break;
			}
		}
	}

	for (int i = 0; i < histogramData.size(); i++)
	{
		string chart = string('*', 10);
		cout << std::string(histogramData[i], '*').c_str() << endl;
	}
}

int main()
{
	LehmerRand lr;

	// 2.1 Uniform distribution
	vector<double> uniform;
	double a = 10;
	double b = 500;
	for (double i = 0; i < 1; i+=0.01)
	{
		double num = uniformDistribution(a, b, i);
		uniform.push_back(num);
	}

	//printHistogram(uniform);

	// 2.2 Gaussian distribution
	vector<double> gaussian;
	double m = 0;
	double sigma = 1;
	for (int i = 0; i < 4000; i++)
	{
		double num = gaussianDistribution(m, sigma);
		gaussian.push_back(num);
	}

	printHistogram(gaussian, 80);

	// 2.3 Exponencial distribution
	vector<double> exponent;
	double lambda = 0.5;
	for (int i = 0; i < 250; i++)
	{
		double num = exponentDistribution(lambda, lr.Rand());
		//cout << num << endl;
		exponent.push_back(num);
	}

	//printHistogram(exponent);

	// 2.3 Gamma distribution
	vector<double> gamma;
	double nu = 9;
	double lambda2 = 0.5;
	for (int i = 0; i < 500; i++)
	{
		double num = gammaDistribution(nu, lambda2);
		gamma.push_back(num);
	}

	//printHistogram(gamma, 30);

	// 2.4 Triangle distribution
	vector<double> triangle;
	double a2 = 10;
	double b2 = 20;
	for (int i = 0; i < 1000; i++)
	{
		double num = triangleDistribution(a2, b2, lr.Rand(), lr.Rand());
		triangle.push_back(num);
	}

	//printHistogram(triangle);

	// 2.5 Simpson's distribution
	vector<double> simpsons;
	double a3 = 10;
	double b3 = 20;
	for (int i = 0; i < 4000; i++)
	{
		double num = simpsonsDistribution(a2, b2, lr.Rand(), lr.Rand());
		simpsons.push_back(num);
	}

	printHistogram(simpsons, 80);

	system("pause");
    return 0;
}