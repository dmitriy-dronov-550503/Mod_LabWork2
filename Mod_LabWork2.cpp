// Mod_LabWork2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>

#include "LehmerRand.h"
#include "DistributionGenerator.h"

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

void printHistogram(vector<double> xs, uint32_t histogramSize = 40)
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
	cout << "Welcome to the second laboratory work by modeling discipline" << endl;
	system("pause");

	LehmerRand lr;
	DistributionGenerator dgen;
	int maxGenerateNumber = 1000;

	// 2.1 Uniform distribution
	cout << "Uniform distribution" << endl;
	vector<double> uniform;
	double a = 10;
	double b = 500;
	for (double i = 0; i < 1; i+=0.01)
	{
		double num = dgen.Uniform(a, b);
		uniform.push_back(num);
	}

	printHistogram(uniform);
	system("pause");
	system("cls");

	// 2.2 Gaussian distribution
	cout << "Gaussian distribution" << endl;
	vector<double> gaussian;
	double m = 0;
	double sigma = 1;
	for (int i = 0; i < maxGenerateNumber; i++)
	{
		double num = dgen.Gaussian(m, sigma);
		gaussian.push_back(num);
	}

	printHistogram(gaussian);
	system("pause");
	system("cls");

	// 2.3 Exponencial distribution
	cout << "Exponencial distribution" << endl;
	vector<double> exponent;
	double lambda = 0.5;
	for (int i = 0; i < maxGenerateNumber; i++)
	{
		double num = dgen.Exponencial(lambda);
		//cout << num << endl;
		exponent.push_back(num);
	}

	printHistogram(exponent);
	system("pause");
	system("cls");

	// 2.4 Gamma distribution
	cout << "Gamma distribution" << endl;
	vector<double> gamma;
	double nu = 9;
	double lambda2 = 0.5;
	for (int i = 0; i < maxGenerateNumber; i++)
	{
		double num = dgen.Gamma(nu, lambda);
		gamma.push_back(num);
	}

	printHistogram(gamma);
	system("pause");
	system("cls");

	// 2.5 Triangle distribution
	cout << "Triangle distribution" << endl;
	vector<double> triangle;
	double a2 = 10;
	double b2 = 20;
	for (int i = 0; i < maxGenerateNumber; i++)
	{
		double num = dgen.Triangle_Up(a2, b2);
		triangle.push_back(num);
	}

	printHistogram(triangle);
	system("pause");
	system("cls");

	// 2.6 Simpson's distribution
	cout << "Simpson's distribution" << endl;
	vector<double> simpsons;
	double a3 = 10;
	double b3 = 20;
	for (int i = 0; i < maxGenerateNumber; i++)
	{
		double num = dgen.Simpsons(a3, b3);
		simpsons.push_back(num);
	}

	printHistogram(simpsons);
	system("pause");
	system("cls");

	int stars;
	cout << "Please, rate this work 1 - 5 start" << endl;
	cin >> stars;
	cout <<

	system("pause");
    return 0;
}