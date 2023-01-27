#include <iostream>
#include <string>
#include <Windows.h>

struct Account {
    int             acc_num;
    std::string     name;
    double          balance;
};

void changeBalance(Account& account, double new_balance) {

    account.balance = new_balance;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);

    Account account;
    double new_balance;

    std::cout << "Введите номер счёта : ";
    std::cin >> account.acc_num;

    std::cout << "Введите имя владельца : ";
    std::cin >> account.name;

    std::cout << "Введите баланс : ";
    std::cin >> account.balance;

    std::cout << "Введите новый баланс : ";
    std::cin >> new_balance;

    changeBalance(account, new_balance);

    std::cout << "Ваш счёт : " << account.name << ", " << account.acc_num << ", " << account.balance << std::endl;
    
    return 0;
}
