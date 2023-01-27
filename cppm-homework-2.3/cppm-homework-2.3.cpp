#include <iostream>

struct Address {
    std::string     country;
    std::string     city;
    std::string     street;
    int             building;
    int             apt;
    int             postal_code;
};

void printStruct(const Address& address) {

    std::cout << "Страна: " << address.country << "\n";
    std::cout << "Город: " << address.city << "\n";
    std::cout << "Улица: " << address.street << "\n";
    std::cout << "Номер дома: " << address.building << "\n";
    std::cout << "Номер квартиры: " << address.apt << "\n";
    std::cout << "Индекс: " << address.postal_code << "\n";
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    const int count = 2;

    Address struct_arr[count] = {
        { "Россия", "Москва", "Арбат", 12, 8, 123456 },
        { "Россия", "Ижевск", "Пушкина", 59, 143, 953769 }
    };

    for (int i = 0; i < count; ++i) {

        printStruct(struct_arr[i]);
    }
}