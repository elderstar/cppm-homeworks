#include <iostream>

int main() {

	system("chcp 1251");

	std::string input;

	while(true) {
		std::cout << "������� ���: ";
		std::cin >> input;
		if (input != "") {
			std::cout << "������������, " << input << "!" << std::endl;
			break;
		}
	};

	return 0;
}