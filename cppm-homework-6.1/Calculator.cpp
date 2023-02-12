#include "Calculator.h"

double addition(double num1, double num2) {

	return num1 + num2;
}

double subtraction(double num1, double num2) {

	return num1 - num2;
}

double multiplication(double num1, double num2) {

	return num1 * num2;
}

double division(double num1, double num2) {

	return num1 / num2;
}

double exponentiation(double num1, double num2) {

	int tmp = num1;
	for (int i = 1; i < num2; i++) {
		num1 *= tmp;
	}
	return num1;
}