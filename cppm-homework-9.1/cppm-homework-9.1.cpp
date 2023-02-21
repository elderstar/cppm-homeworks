#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	int common_denominator;
	int new_numerator_;
	int new_denominator_;

	void bringToCommonDenominator(Fraction& right) {

		common_denominator = denominator_ * right.denominator_;
		new_numerator_ = numerator_ * (common_denominator / denominator_);
		right.new_numerator_ = right.numerator_ * (common_denominator / right.denominator_);
		new_denominator_ = common_denominator;
		right.new_denominator_ = common_denominator;
	}

public:
	Fraction(int numerator, int denominator)
	{
		if (denominator == 0)
			throw std::domain_error("Denominator is 0");

		numerator_ = numerator;
		denominator_ = denominator;
		new_numerator_ = 0;
		new_denominator_ = 0;
		common_denominator = 0;
	}

	bool operator==(Fraction& right) {

		if (denominator_ == right.denominator_) {

			if (numerator_ == right.numerator_) {

				return true;
			}
			else {
				return false;
			}
		}
		else {
			bringToCommonDenominator(right);
			if (new_numerator_ == right.new_numerator_) {

				return true;
			}
			else {
				return false;
			}
		}
	}

	bool operator!=(Fraction& right) {

		return !(this->operator==(right));
	}

	bool operator<(Fraction& right) {

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
		bringToCommonDenominator(right);
		if (new_numerator_ < right.new_numerator_) {

			return true;
		}
		else {
			return false;
		}
	}

	bool operator>(Fraction& right) {

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
			bringToCommonDenominator(right);
			if (new_numerator_ > right.new_numerator_) {

				return true;
			}
			else {
				return false;
			}
		}
	}

	bool operator<=(Fraction& right) {

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
			bringToCommonDenominator(right);
			if (new_numerator_ > right.new_numerator_) {

				return false;
			}
			else {
				return true;
			}
		}
	}
	bool operator>=(Fraction& right) {
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
			bringToCommonDenominator(right);
			if (new_numerator_ < right.new_numerator_) {

				return false;
			}
			else {
				return true;
			}
		}
	}
};

int main()
{
	try {
		Fraction f1(4, 3);
		Fraction f2(6, 11);

		std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
		std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
		std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
		std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
		std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
		std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
