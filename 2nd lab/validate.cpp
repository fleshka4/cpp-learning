#include <bits/stdc++.h>

int getValue() {
	int n;
	while (!(std::cin >> n))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');

		std::cout << "Ошибка введено неверное значение! ";
	}
	return abs(n);
}

double getRealValue() {
	double n;
	while (!(std::cin >> n))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');

		std::cout << "Ошибка введено неверное значение! ";
	}
	return abs(n);
}

double getInterval() {
	double n;
	while (!(std::cin >> n) || (abs(n) > 1))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');

		std::cout << "Ошибка введено неверное значение! ";
	}
	return n;
}