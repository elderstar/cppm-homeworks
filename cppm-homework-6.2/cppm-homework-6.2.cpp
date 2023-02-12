#include <iostream>
#include "Counter.Class.h"
#include "string"

void count(Counter& counter)
{
    char command = '0';

    do {
        std::cout << "Введите команду('+', '-', '=' или 'x') : ";
        std::cin >> command;
        switch (command) {
        case '+':
            std::cout << counter.add() << "\n";
            break;
        case '-':
            std::cout << counter.subtract() << "\n";
            break;
        case '=':
            std::cout << counter.getVal() << "\n";
            break;
        }
    } while (command != 'x');
}

bool isNumber(std::string& str) {

    for (char ch : str)
    {
        if (std::isdigit(ch) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    system("chcp 1251");
    std::string answer;
    std::string input;
    int start_value = 0;

    while (true) {
        std::cout << "Вы хотите указать начальное значение счётчика ? Введите да или нет : ";
        std::cin >> answer;

        if (answer == "да") {

            while (true) {

                std::cout << "Введите начальное значение счётчика : ";

                std::cin >> input;
                if (isNumber(input) && input != "")
                {
                    start_value = std::stoi(input);
                    break;
                };
            }
            Counter counter(start_value);
            count(counter);
            break;
        }
        else if(answer == "нет"){
            Counter counter;
            count(counter);
            break;
        }
    }

    std::cout << "До свидания!";
    return 0;
}