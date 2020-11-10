#include <bits/stdc++.h>
#include "validate.h"

bool flag = 0;

double F(double i, double absError, long long int numberMax)
{
	flag = 0;
	double a = 1, sum = 1;
	for (long long int j = 0; j < numberMax; j++)
	{
		a *= i * i / ((2 * j + 1) * (2 * j + 2));
		if (abs(a) <= absError) {
			flag = true;
			return sum;
		}
		sum += a;
	}
	return sum;
}

int main()
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(5);
	setlocale(LC_ALL, "ru");
	long long int numberMax;
	double absError, step, i, X1, X2;

	std::cout << "Введите интервал от: ";
	X1 = getInterval();
	std::cout << "Введите интервал до: ";
	X2 = getInterval();
	std::cout << "Введите максимальное количество шагов: ";
	numberMax = getValue();
	std::cout << "Введите погрешность: ";
	absError = getRealValue();
	std::cout << "Введите шаг: ";
	step = getRealValue();

	for (i = X1; i < X2; i += step)
	{
		std::cout << (i) << "  " << cosh(i) << "  " << F(i, absError, numberMax) << "  ";
		if (flag) {
			std::cout << "Погрешность достигнута" << "\n";
		}
		else {
			std::cout << "Погрешность не достигнута" << "\n";
		}
	}
	return 0;
}
