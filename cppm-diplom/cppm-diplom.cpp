#include <iostream>
#include <vector>
#include <string>
#include "./RacingSimulatorLib/AircraftClass.h"
#include "./RacingSimulatorLib/AllTerrainBootsClass.h"
#include "./RacingSimulatorLib/BroomClass.h"
#include "./RacingSimulatorLib/CamelClass.h"
#include "./RacingSimulatorLib/CamelSpeedboatClass.h"
#include "./RacingSimulatorLib/CentaurClass.h"
#include "./RacingSimulatorLib/EagleClass.h"
#include "./RacingSimulatorLib/GroundClass.h"
#include "./RacingSimulatorLib/MagicCarpetClass.h"
#include "./RacingSimulatorLib/VehicleClass.h"
#include "./RacingSimulatorLib/RaceClass.h"
#include "./RacingSimulatorLib/GroundRaceClass.h"
#include "./RacingSimulatorLib/AirRaceClass.h"

bool isNumber(std::string& str) {

	for (char ch : str) {
		if (isdigit(ch) == 0) {
			return false;
		}
	}
	return true;
}

void printArray(std::vector<std::unique_ptr<Vehicle>>& arr, size_t size) {

	for (int i = 0; i < size; ++i)
	{
		std::cout << i + 1 << ". " << arr[i]->getVehicleName() << "\n";
	}
}

void clearConsole() {
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

void sortBubble(Vehicle** arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - 1; ++j) {

			if ((*arr)[j] > (*arr)[j + 1]) {

				Vehicle temp = (*arr)[j];
				(*arr)[j] = (*arr)[j + 1];
				(*arr)[j + 1] = temp;
			}
		}
	}
}

int start(std::string& input, Race& race, std::vector<std::unique_ptr<Vehicle>>& vehicles) {

	size_t participants_count = 0;
	Vehicle* ptr_participantList = new Vehicle[participants_count];

	while (true) {
		clearConsole();
		std::cout << "Укажите длину дистанции (должна быть положительна): ";
		std::getline(std::cin, input);

		if (input != "" && isNumber(input))
		{
			race.setLength(abs(stoi(input)));
			break;
		}
	}

	while (true) {
		clearConsole();
		std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << "\n";
		std::cout << "1. Зарегистрировать транспорт" << "\n";

		if (participants_count > 1)
		{
			std::cout << "2. Начать гонку" << "\n";
		}
		std::cout << "Выберите действие: ";

		std::getline(std::cin, input);

		if (input != "" && isNumber(input))
		{
			if (stoi(input) == 1) {

				clearConsole();
				bool finish_registration = false;
				while (!finish_registration) {

					std::cout << race.getTitle() << ". Расстояние: " << race.getLength() << "\n";

					if (participants_count > 0)
					{
						std::cout << "Зарегистрированные транспортные средства: ";
						for (int i = 0; i < participants_count; ++i) {

							std::cout << ptr_participantList[i].getVehicleName();
							if (i < participants_count - 1)
								std::cout << ", ";
						}
						std::cout << "\n";
					}
					printArray(vehicles, 7);
					std::cout << "0. Закончить регистрацию" << "\n";
					std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";

					while (true) {
						std::getline(std::cin, input);

						if (input != "" && isNumber(input))
						{
							int answer = stoi(input);
							if (answer == 0) {
								finish_registration = true;
								break;
							}
							if (answer > 0 && answer < 8) {
								clearConsole();
								try {
									ptr_participantList = race.registerVehicle(ptr_participantList, vehicles[answer - 1], participants_count);
									std::cout << ptr_participantList[participants_count - 1].getVehicleName() << " успешно зарегистрирован!" << "\n";
								}
								catch (std::exception e) {
									std::cout << e.what() << "\n";
								}
								break;
							}								
						}
						clearConsole();
						break;
					}
				}
			}
			else if (participants_count > 1 && stoi(input) == 2) {
				clearConsole();
				std::cout << "Результаты гонки:" << "\n";

				for (int i = 0; i < participants_count; ++i) {

					ptr_participantList[i].setResult((*ptr_participantList[i].getParChildPtr())->calculateMovementTime(race.getLength()));
				}

				sortBubble(&ptr_participantList, participants_count);

				for (int i = 0; i < participants_count; ++i) {

					std::cout << i + 1 << ". " << ptr_participantList[i].getVehicleName() << ". Время: " << ptr_participantList[i].getResult() << "\n";
				}
				std::cout << "\n";
				std::cout << "1. Провести еще одну гонку" << "\n";
				std::cout << "2. Выйти" << std::endl;
				std::cout << "Выберите действие: ";

				while (true) {
					std::getline(std::cin, input);

					if (input != "" && isNumber(input))
					{
						if (stoi(input) == 2) {
							exit(0);
						}
						else if (stoi(input) == 1) {
							participants_count = 0;
							ptr_participantList = new Vehicle[participants_count];
							clearConsole();
							return 0;
						}
					}
				}
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	std::string input;

	std::vector<std::unique_ptr<Vehicle>>vehicles;

	vehicles.push_back(std::make_unique<AllTerrainBoots>());
	vehicles.push_back(std::make_unique<Broom>());
	vehicles.push_back(std::make_unique<Camel>());
	vehicles.push_back(std::make_unique<Centaur>());
	vehicles.push_back(std::make_unique<Eagle>());
	vehicles.push_back(std::make_unique<CamelSpeedboat>());
	vehicles.push_back(std::make_unique<MagicCarpet>());

	bool raceCreated = false;
	int raceType = 0;

	std::cout << "Добро пожаловать в гоночный симулятор!" << "\n";

	while (!raceCreated) {
		std::cout << "1. Гонка для наземного транспорта" << "\n";
		std::cout << "2. Гонка для воздушного трансопрта" << "\n";
		std::cout << "3. Гонка для наземного и воздушного транспорта" << "\n";
		std::cout << "Выберите тип гонки: ";

		std::getline(std::cin, input);

		if (input != "" && isNumber(input))
		{
			raceType = stoi(input);
			switch (raceType) {
				case 1:
				{
					GroundRace race;
					start(input, race, vehicles);
					break;
				}
				case 2:
				{
					AirRace race;
					start(input, race, vehicles);
					break;
				}
				case 3:
				{
					Race race;
					start(input, race, vehicles);
					break;
				}
				default:
					clearConsole();
			}
		}
	}

	return 0;
}