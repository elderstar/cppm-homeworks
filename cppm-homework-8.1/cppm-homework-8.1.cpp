#include <iostream>
#include <string>

class BadLength : public std::exception
{
public:

    const char* what() const override
    {
        return "Вы ввели слово запретной длины! До свидания";
    }
};

int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length)
        throw BadLength();

    return str.length();
}

bool isNumber(std::string str) 
{
    for (char ch : str) {
        
        if (isdigit(ch) == 0) {

            return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    std::string input;
    int forbidden_length = 0;

    while (true) 
    {
        std::cout << "Введите запретную длину: ";

        std::getline(std::cin, input);

        if (input != "" && isNumber(input))
        {
            forbidden_length = std::stoi(input);
            break;
        }
    }
    
    while (true)
    {
        std::cout << "Введите слово: ";
        std::cin >> input;

        try {
            int input_length = function(input, forbidden_length);
            
            std::cout << "Длина слова " << '"' << input << '"' << " равна: " << input_length << "\n";
        }
        catch (const BadLength& e) {

            std::cout << e.what() << std::endl;
            break;
        }
    }

    return 0;
}