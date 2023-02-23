#include <iostream>

int main() {

	system("chcp 1251");

	std::string input;

	while(true) {
		std::cout << "Введите имя: ";
		std::cin >> input;
		if (input != "") {
			std::cout << "Здравствуйте, " << input << "!" << std::endl;
			break;
		}
	};

	return 0;
}