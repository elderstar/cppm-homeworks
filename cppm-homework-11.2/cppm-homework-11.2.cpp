#include <iostream>
#include"Leaver.h"
#include<string>

int main()
{
    system("chcp 1251");

    std::string input;
    Leaver leaver;

    do {
        std::cout << "Введите имя :";
        std::getline(std::cin, input);

        #ifdef _WIN32
                system("cls");
        #else
                system("clear");
        #endif // _WIN32

    } while (input.empty() || input[0] == ' ');
    
    std::cout << leaver.leave(input);
    return 0;
}