#include <iostream>
#include"Fraction.h"
#include<string>

bool isNumber(std::string str) {
	
	for (char ch : str)
	{
		if (isdigit(ch) == 0)
		{
			return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& left, Fraction& right) {

	left << right.getNumerator();

	if (right.getDenominator() != 1)
	{
		left << "/" << right.getDenominator();
	}

	return left;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int fractions[2][2] = {};
	std::string input;
	std::string fraction_titles[2] = { "числитель", "знаменатель" };
	int result[2] = {};

	for (int i = 0; i < 2; ++i) {

		for (int j = 0; j < 2; ++j) {
			while (true) {
				std::cout << "Введите " << fraction_titles[j] << " дроби " << i + 1 << ": ";
				std::getline(std::cin, input);

				if (input != "" && isNumber(input))
				{
					fractions[i][j] = stoi(input);
					break;
				}
			}
		}
	}

	try {
		Fraction f1(fractions[0][0], fractions[0][1]);
		Fraction f2(fractions[1][0], fractions[1][1]);
		
		Fraction f3 = (f1 + f2);
		std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " + " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << f3 << "\n";
		f3 = (f1 - f2);
		std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " - " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << f3 << "\n";
		f3 = (f1 * f2);
		std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << f3 << "\n";
		f3 = (f1 / f2);
		std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " / " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << f3 << "\n";
		
		std::cout << "++" << f1.getNumerator() << "/" << f1.getDenominator() << " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
		f3 = (++f1 * f2);
		std::cout << f3 << "\n";
		std::cout << "Значение дроби 1 = " << f1 << "\n";
		
		std::cout << f1.getNumerator() << "/" << f1.getDenominator() << "++" << " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
		f3 = (f1++ * f2);
		std::cout << f3 << "\n";
		std::cout << "Значение дроби 1 = " << f1 << "\n";

		std::cout << "--" << f1.getNumerator() << "/" << f1.getDenominator() << " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
		f3 = (--f1 * f2);
		std::cout << f3 << "\n";
		std::cout << "Значение дроби 1 = " << f1 << "\n";

		std::cout << f1.getNumerator() << "/" << f1.getDenominator() << "--" << " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
		f3 = (f1-- * f2);
		std::cout << f3 << "\n";
		std::cout << "Значение дроби 1 = " << f1 << "\n";
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}