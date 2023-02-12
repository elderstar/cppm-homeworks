#include <iostream>

#define MODE 1

#if MODE == 1

#include <string>

long add(long num1, long num2)
{
    return num1 + num2;
}

bool isNumber(std::string& str) {
    for (char ch : str) {
        if (isdigit(ch) == 0)
        {
            return false;
        }
    }
    return true;
}

#endif // MODE 1

int main()
{
    setlocale(LC_ALL, "Russian");

#ifndef MODE

    std::cout << "MODE Не определена. Oпределите MODE чтобы продолжить.\n";

#elif MODE == 0

    std::cout << "Работаю в режиме тренировки.\n";

#elif MODE == 1

    std::cout << "Работаю в боевом режиме.\n";

    std::string input;
    long nums[2] = {};

    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i) {
        while (true)
        {
            std::cout << "Введите число " << i + 1 << " : ";
            std::getline(std::cin, input);
            if (isNumber(input) && input != "") {

                nums[i] = std::stol(input);
                break;
            }
        }
    }

    std::cout << "Результат сложения : " << add(nums[0], nums[1]);
#else

    std::cout << "Неизвестный режим.Завершение работы.\n";
    
#endif // !MODE

    return 0;
}