#include <iostream>

class Counter 
{
public:

    Counter(int value) {
        start_value = value;
    };
    Counter() {
        start_value = 0;
    };
    ~Counter() {};

    void subtract() {
    
        std::cout << --this->start_value << "\n";
    }

    void add() {

        std::cout << ++this->start_value << "\n";
    }

    void printVal() {

        std::cout << this->start_value << "\n";
    }
private:

    int start_value;
};

void count(Counter& counter) 
{
    char command = '0';

    do {

        std::cout << "Введите команду('+', '-', '=' или 'x') : ";
        std::cin >> command;
        switch (command) {
        case '+':
            counter.add();
            break;
        case '-':
            counter.subtract();
            break;
        case '=':
            counter.printVal();
            break;
        }
    } while (command != 'x');
}

int main()
{
    system("chcp 1251");
    std::string answer;

    std::cout << "Вы хотите указать начальное значение счётчика ? Введите да или нет : ";
    std::cin >> answer;

    if (answer == "да") {
        int start_value = 0;
        std::cout << "Введите начальное значение счётчика : ";
        std::cin >> start_value;
        Counter counter(start_value);
        count(counter);
    }
    else {
        Counter counter;
        count(counter);
    }
    
    std::cout << "До свидания!";
    return 0;
}