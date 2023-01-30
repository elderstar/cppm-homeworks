#include <iostream>

class Calculator
{
public:

    double add(double num1, double num2)
    {
        return num1 + num2; 
    }

    double multiply(double num1, double num2)
    {
        return num1 * num2;
    }

    double subtract_1_2(double num1, double num2)
    {
        return num1 - num2;
    }

    double subtract_2_1(double num1, double num2)
    {
        return num2 - num1;
    }

    double divide_1_2(double num1, double num2)
    {
        return num1 / num2;
    }

    double divide_2_1(double num1, double num2)
    {
        return num2 / num1;
    }

    bool set_num1(double num1)
    {
        if (num1 == 0) {
            std::cout << "Неверный ввод!\n";
            return false;
        }
        else {
            this->num1 = num1;
            return true;
        }
    }

    bool set_num2(double num2)
    {
        if (num2 == 0) {
            std::cout << "Неверный ввод!\n";
            return false;
        }
        else {

            this->num2 = num2;
            return true;
        }
    }

    ~Calculator() {};

private:
    double num1, num2;
};

void printCalculations(Calculator& calc, double num1, double num2) {

    std::cout << "num1 + num2 = " << calc.add(num1, num2) << "\n";
    std::cout << "num1 - num2 = " << calc.subtract_1_2(num1, num2) << "\n";
    std::cout << "num2 - num1 = " << calc.subtract_2_1(num1, num2) << "\n";
    std::cout << "num1 * num2 = " << calc.multiply(num1, num2) << "\n";
    std::cout << "num1 / num2 = " << calc.divide_1_2(num1, num2) << "\n";
    std::cout << "num2 / num1 = " << calc.divide_2_1(num1, num2) << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double num1 = 0;
    double num2 = 0;

    Calculator calc{};

    do {
        do {
            std::cout << "Введите num1 : ";
            std::cin >> num1;
        } while (!calc.set_num1(num1));

        do {
            std::cout << "Введите num2 : ";
            std::cin >> num2;
        } while (!calc.set_num2(num2));

        printCalculations(calc, num1, num2);

    } while (true);

    return 0;
}