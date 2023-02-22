#include <iostream>
#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
	if (denominator == 0)
		throw std::domain_error("Denominator is 0");

	numerator_ = numerator;
	denominator_ = denominator;
	new_numerator_ = 0;
	new_denominator_ = 0;
	common_denominator = 0;
}

void Fraction::cutFraction(Fraction& fraction)
{
	for (int i = 2; i <= fraction.numerator_ && i <= fraction.denominator_;)
	{
		if (fraction.numerator_ % i == 0 && fraction.denominator_ % i ==0) {
			fraction.numerator_ /= i;
			fraction.denominator_ /= i;
		}
		else {
			++i;
		}
	}
}

void Fraction::bringToCommonDenominator(Fraction& right) {

	//common_denominator = denominator_ * right.denominator_;
	int max = std::max(denominator_, right.denominator_);
	for (int i = 0; i <= denominator_ * right.denominator_; ++i) {
		if ((max + i) % denominator_ == 0 && (max + i) % right.denominator_ == 0) {
			common_denominator = max + i;
			break;
		}
	}
	new_numerator_ = numerator_ * (common_denominator / denominator_);
	right.new_numerator_ = right.numerator_ * (common_denominator / right.denominator_);
	new_denominator_ = common_denominator;
	right.new_denominator_ = common_denominator;
}
int Fraction::getNumerator() {

	return numerator_;
};

int Fraction::getDenominator() {

	return denominator_;
};

Fraction Fraction::operator+(Fraction& right) {

	int result_numerator = 1;
	int result_denominator = 1;

	if (denominator_ == right.denominator_) {
		result_numerator = numerator_ + right.numerator_;
		result_denominator = denominator_;
	}
	else {
		Fraction::bringToCommonDenominator(right);
		result_numerator = new_numerator_ + right.new_numerator_;
		result_denominator = common_denominator;
	}

	return Fraction(result_numerator, result_denominator);
}

Fraction& Fraction::operator++() {

	Fraction one = Fraction(1, 1);
	*this = this->operator+(one);

	return *this;
}

Fraction& Fraction::operator++(int) {

	Fraction one = Fraction(1, 1);
	Fraction temp = *this;
	*this = this->operator+(one);

	return temp;
}

Fraction& Fraction::operator--() {

	Fraction one = Fraction(1, 1);
	*this = this->operator-(one);

	return *this;
}

Fraction& Fraction::operator--(int) {

	Fraction one = Fraction(1, 1);
	Fraction temp = *this;
	*this = this->operator-(one);

	return temp;
}

Fraction Fraction::operator-(Fraction& right) {

	int result_numerator = 1;
	int result_denominator = 1;

	if (denominator_ == right.denominator_) {
		if (this->operator>=(right)) {
			result_numerator = numerator_ - right.numerator_;
			result_denominator = denominator_;
		}
		else {
			result_numerator = -(right.numerator_ - numerator_);
			result_denominator = right.denominator_;
		}
	}
	else {
		Fraction::bringToCommonDenominator(right);
		if (this->operator>=(right)) {
			result_numerator = new_numerator_ - right.new_numerator_;
			result_denominator = common_denominator;
		}
		else {
			result_numerator = -(right.new_numerator_ - new_numerator_);
			result_denominator = common_denominator;
		}
	}

	return Fraction(result_numerator, result_denominator);
}

Fraction Fraction::operator*(Fraction& right) {

	Fraction result = Fraction(numerator_ * right.numerator_ , denominator_ * right.denominator_);
	cutFraction(result);
	return result;
}

Fraction Fraction::operator/(Fraction& right) {

	Fraction result = Fraction(numerator_ * right.denominator_, denominator_ * right.numerator_);
	cutFraction(result);
	return result;
}

bool Fraction::operator==(Fraction& right) {

	if (denominator_ == right.denominator_) {

		if (numerator_ == right.numerator_) {

			return true;
		}
		else {
			return false;
		}
	}
	else {
		Fraction::bringToCommonDenominator(right);
		if (new_numerator_ == right.new_numerator_) {

			return true;
		}
		else {
			return false;
		}
	}
}

bool Fraction::operator!=(Fraction& right) {

	return !(this->operator==(right));
}

bool Fraction::operator<(Fraction& right) {

	if (denominator_ == right.denominator_) {

		if (numerator_ < right.numerator_) {

			return true;
		}
		else {
			return false;
		}
	}
	else if (numerator_ == right.numerator_) {

		if (denominator_ > right.denominator_) {

			return true;
		}
		else {
			return false;
		}
	}
	Fraction::bringToCommonDenominator(right);
	if (new_numerator_ < right.new_numerator_) {

		return true;
	}
	else {
		return false;
	}
}

bool Fraction::operator>(Fraction& right) {

	if (denominator_ == right.denominator_) {

		if (numerator_ > right.numerator_) {

			return true;
		}
		else {
			return false;
		}
	}
	else if (numerator_ == right.numerator_) {

		if (denominator_ < right.denominator_) {

			return true;
		}
		else {
			return false;
		}
	}
	else {
		Fraction::bringToCommonDenominator(right);
		if (new_numerator_ > right.new_numerator_) {

			return true;
		}
		else {
			return false;
		}
	}
}

bool Fraction::operator<=(Fraction& right) {

	if (denominator_ == right.denominator_) {

		if (numerator_ > right.numerator_)
		{
			return false;
		}
		else {
			return true;
		}
	}
	else if (numerator_ == right.numerator_) {

		if (denominator_ > right.denominator_)
		{
			return true;
		}
		else {
			return false;
		}
	}
	else {
		Fraction::bringToCommonDenominator(right);
		if (new_numerator_ > right.new_numerator_) {

			return false;
		}
		else {
			return true;
		}
	}
}
bool Fraction::operator>=(Fraction& right) {
	if (denominator_ == right.denominator_) {

		if (numerator_ < right.numerator_)
		{
			return false;
		}
		else {
			return true;
		}
	}
	else if (numerator_ == right.numerator_) {

		if (denominator_ < right.denominator_)
		{
			return true;
		}
		else {
			return false;
		}
	}
	else {
		Fraction::bringToCommonDenominator(right);
		if (new_numerator_ < right.new_numerator_) {

			return false;
		}
		else {
			return true;
		}
	}
}