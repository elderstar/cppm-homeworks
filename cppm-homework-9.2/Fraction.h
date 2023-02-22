#pragma once
#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	int common_denominator;
	int new_numerator_;
	int new_denominator_;

	void bringToCommonDenominator(Fraction& right);

public:

	Fraction(int numerator, int denominator);
	void cutFraction(Fraction& fraction);
	int getNumerator();
	int getDenominator();
	friend std::ostream& operator<<(std::ostream& left, Fraction& right);
	Fraction operator+(Fraction& right);
	Fraction& operator++();
	Fraction& operator++(int);
	Fraction operator-(Fraction& right);
	Fraction& operator--();
	Fraction& operator--(int);
	Fraction operator*(Fraction& right);
	Fraction operator/(Fraction& right);

	bool operator==(Fraction& right);
	bool operator!=(Fraction& right);
	bool operator<(Fraction& right);
	bool operator>(Fraction& right);
	bool operator<=(Fraction& right);
	bool operator>=(Fraction& right);
};