#include <iostream>

enum class Months
{
    январь = 1, февраль, март, апрель, май, июнь, июль, август, сентябрь, октябрь, ноябрь, декабрь
};

void printMonth(int month_num) {
    Months month = static_cast<Months>(month_num);

    switch (month)
    {
    case Months::январь:
        std::cout << "Январь\n";
        break;
    case Months::февраль:
        std::cout << "Февраль\n";
        break;
    case Months::март:
        std::cout << "Март\n";
        break;
    case Months::апрель:
        std::cout << "Апрель\n";
        break;
    case Months::май:
        std::cout << "Май\n";
        break;
    case Months::июнь:
        std::cout << "Июнь\n";
        break;
    case Months::июль:
        std::cout << "Июль\n";
        break;
    case Months::август:
        std::cout << "Август\n";
        break;
    case Months::сентябрь:
        std::cout << "Сентябрь\n";
        break;
    case Months::октябрь:
        std::cout << "Октябрь\n";
        break;
    case Months::ноябрь:
        std::cout << "Ноябрь\n";
        break;
    case Months::декабрь:
        std::cout << "Декабрь\n";
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int month_num = 0;

    do {
        std::cout << "Введите номер месяца: ";
        std::cin >> month_num;
        month_num = static_cast<int>(month_num);    // возможно явное преобразование лишнее

        if (month_num > 12 || month_num < 0) {
            std::cout << "Неправильный номер!\n";
        }
        else {
            printMonth(month_num);
        }

    } while (month_num != 0);

    std::cout << "До свидания";

    return 0;
   
}