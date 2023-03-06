#include <iostream>
#include <vector>
#include <string>
#include "AircraftClass.h"
#include "AllTerrainBootsClass.h"
#include "BroomClass.h"
#include "CamelClass.h"
#include "CamelSpeedboatClass.h"
#include "CentaurClass.h"
#include "EagleClass.h"
#include "GroundClass.h"
#include "MagicCarpetClass.h"
#include "VehicleClass.h"
#include <type_traits>
#include <typeinfo>

class Race {

public:
	Race() {
		length = 0;
		title = "Гонка для наземного и воздушного транспорта";
	};
	~Race() {};
	Race* getParChildPtr() {
		return par_child;
	}

	void setParChildPtr(Race* _par_child) {
		par_child = _par_child;
	}

	bool checkNewParticipant(Vehicle*& participants, std::unique_ptr<Vehicle>& vehicle, size_t& participants_count) {
		std::string new_participant_name = vehicle->getVehicleName();

		for (int i = 0; i < participants_count; ++i) {
			if (participants[i].getVehicleName() == new_participant_name)
				return false;
		}
		return true;
	}

	bool virtual checkVehicleType(std::unique_ptr<Vehicle>& vehicle) {
		return true;
	}

	Vehicle* registerVehicle(Vehicle*& participants, std::unique_ptr<Vehicle>& vehicle, size_t& participants_count) {

		if (!checkNewParticipant(participants, vehicle, participants_count))
			throw std::domain_error(vehicle->getVehicleName() + " уже зрегистрирован!");
		if(!this->getParChildPtr()->checkVehicleType(vehicle))
			throw std::domain_error("Попытка зарегистрировать неправильный тип транспортного средства!");
		
		vehicle->setParChildPtr(&vehicle);

		if (participants_count > 0) {

			Vehicle* temp_participants = new Vehicle[++participants_count];

			for (int i = 0; i < participants_count - 1; ++i)
			{
				temp_participants[i] = participants[i];
			}

			delete[] participants;
			participants = temp_participants;
			participants[participants_count - 1] = *vehicle;
		}
		else {
			delete[] participants;
			participants = new Vehicle[++participants_count];
			participants[participants_count - 1] = *vehicle;
		}
		return participants;
	}

	void setLength(unsigned int _length) {

		length = _length;
	}

	unsigned int getLength() {

		return length;
	}

	std::string getTitle() {

		return title;
	}

protected:
	unsigned int length;
	std::string title;
	Race* par_child;

};

class GroundRace : public Race {

public:
	GroundRace() {
		title = "Гонка для наземного транспорта";
	};
	~GroundRace() {};
	
	bool checkVehicleType(std::unique_ptr<Vehicle>& vehicle) override {
		
		if (dynamic_cast<Ground*>(&*vehicle)) {
			return true;
		}
		else {
			return false;
		};
	}

private:
};

class AirRace : public Race {

public:
	AirRace() {
		title = "Гонка для воздушного транспорта";
	};
	~AirRace() {};

	bool checkVehicleType(std::unique_ptr<Vehicle>& vehicle) override {
		
		if (dynamic_cast<Aircraft*>(&*vehicle)) {
			return true;
		}
		else {
			return false;
		};
	}
private:

};

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

void start() {

	std::string input;
	size_t participants_count = 0;
	Vehicle* ptr_participantList = new Vehicle[participants_count];

	//Vehicle vehicles[7] = { AllTerrainBoots(), Broom(), Camel(), Centaur(), Eagle(), CamelSpeedboat(), MagicCarpet() };
	// такой массив объектов класса не позволяет пльзоваться полиморфизмом, виртуальные методы не переопределяются
	
	/*AllTerrainBoots all_terrain_boots = AllTerrainBoots();
	Broom broom = Broom(); 
	Camel camel = Camel();
	Centaur centaur = Centaur();
	Eagle eagle = Eagle();
	CamelSpeedboat camel_speedboat = CamelSpeedboat();
	MagicCarpet magic_carpet = MagicCarpet();*/
	//Vehicle vehicles[7] = { all_terrain_boots, broom, camel, centaur, eagle, camel_speedboat, magic_carpet };
	// 
	// такой способ тоже не привел к нужному результату, получается у всех элементов массива тип данных родительский
	// способ с векторами решил мою проблему, но может все таки можно это сделать через простые массивы? Может я что-то упустил?

	std::vector<std::unique_ptr<Vehicle>>vehicles;
	vehicles.push_back(std::make_unique<AllTerrainBoots>());
	vehicles.push_back(std::make_unique<Broom>());
	vehicles.push_back(std::make_unique<Camel>());
	vehicles.push_back(std::make_unique<Centaur>());
	vehicles.push_back(std::make_unique<Eagle>());
	vehicles.push_back(std::make_unique<CamelSpeedboat>());
	vehicles.push_back(std::make_unique<MagicCarpet>());

	Race race;
	GroundRace ground_race;
	AirRace air_race;

	bool raceCreated = false;
	int raceType = 0;

	while (!raceCreated) {
		std::cout << "1. Гонка для наземного транспорта" << "\n";
		std::cout << "2. Гонка для воздушного трансопрта" << "\n";
		std::cout << "3. Гонка для наземного и воздушного транспорта" << "\n";
		std::cout << "Выберите тип гонки: ";

		std::getline(std::cin, input);
		

		if (input != "" && isNumber(input))
		{
			raceType = stoi(input);
			break;
		}
		
	}

	switch (raceType) {
	case 1:
	{
		race.setParChildPtr(&ground_race);
		air_race.~AirRace();
		break;
	}
	case 2:
	{
		race.setParChildPtr(&air_race);
		ground_race.~GroundRace();
		break;
	}
	case 3:
	{
		race.setParChildPtr(&race);
		ground_race.~GroundRace();
		air_race.~AirRace();
		break;
	}
	default:
		clearConsole();
	}

	//race.setParChildPtr(&race);

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
							raceCreated = false;
							clearConsole();
							start();
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

	std::cout << "Добро пожаловать в гоночный симулятор!" << "\n";

	start();

	return 0;
}