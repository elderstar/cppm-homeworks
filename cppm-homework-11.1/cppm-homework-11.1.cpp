#include <iostream>
#include <string>
#include"Greeter.h"

int main()
{
    system("chcp 1251");
    std::string input;
    Greeter greeter = Greeter();

    do {
        std::cout << "Введите имя :\n";
        std::getline(std::cin, input);

    #ifdef _WIN32
            system("cls");
    #else
            system("clear");
    #endif // _WIN32

    } while (input.empty() || input[0] == ' ');

    std::cout << greeter.greet(input);

    return 0;
}