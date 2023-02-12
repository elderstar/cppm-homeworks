#include <iostream>
#include <string>
#include "Calculator.h"

bool isNumber(std::string& str) {
    for (char ch: str) {
        if (std::isdigit(ch) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    std::string input;
    double first_number = 0;
    double second_number = 0;
    int operation_number = 0;
    double result;

    while (true) {

        std::cout << "Введите первое число : ";
        std::getline(std::cin, input);
        if (isNumber(input) && input != "")
        {
            first_number = std::stol(input);
            break;
        };
    }

    while (true) {

        std::cout << "Введите второе число : ";
        std::getline(std::cin, input);
        if (isNumber(input) && input != "")
        {
            second_number = std::stol(input);
            break;
        };
    }

    while (true) {

        std::cout << "Выберите операцию(1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень) : ";
        std::getline(std::cin, input);
        if (isNumber(input) && input != "")
        {
            operation_number = std::stoi(input);
            if (operation_number > 0 && operation_number < 6) {
                break;
            }
        };
    }
    
    switch (operation_number) {
        case 1 :
            result = addition(first_number, second_number);
            std::cout << first_number << " прибавить к " << second_number << " = " << result << std::endl;
            break;
        case 2 :
            result = subtraction(first_number, second_number);
            std::cout << first_number << " вычесть " << second_number << " = " << result << std::endl;
            break;
        case 3 :
            result = multiplication(first_number, second_number);
            std::cout << first_number << " умножить на " << second_number << " = " << result << std::endl;
            break;
        case 4 :
            result = division(first_number, second_number);
            std::cout << first_number << " делить на " << second_number << " = " << result << std::endl;
            break;
        case 5 :
            result = exponentiation(first_number, second_number);
            std::cout << first_number << " в степени " << second_number << " = " << result << std::endl;
            break;
    }

    return 0;
}