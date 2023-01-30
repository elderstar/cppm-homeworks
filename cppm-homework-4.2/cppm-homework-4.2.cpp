#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class Address
{

public:

    Address(std::string _city, std::string _address, int _building, int _apt) {
        city = _city;
        address = _address;
        building = _building;
        apt = _apt;
    }

    Address() {
        city = "";
        address = "";
        building = 0;
        apt = 0;
    }

    ~Address() {};

    std::string getOutputAddress()
    {
        return city + ", " + address + ", " + std::to_string(building) + ", " + std::to_string(apt);
    }

    std::string getCity() {
        
        return city;
    }

private:

    std::string city;
    std::string address;
    int building;
    int apt;
};

void readFile(std::ifstream& input_file, Address** arr_of_addresses, int addresses_count)
{
    std::string address_arr[4];

    for (int i = 0; i < addresses_count; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            getline(input_file, address_arr[j]);
        }

        arr_of_addresses[i] = new Address(address_arr[0], address_arr[1], stoi(address_arr[2]), stoi(address_arr[3]));
    }
}

int comp(Address* i, Address* j) {

    return i->getCity() < j->getCity();
}

int main()
{
    std::ifstream input_file;
    std::string str;

    input_file.open("in.txt");

    if (!input_file.is_open()) {

        return 0;
    }

    while (getline(input_file, str)) {
        if (!input_file.eof()) {
            int addresses_count = std::stoi(str);
            Address** arr_of_addresses = new Address * [addresses_count];

            if (addresses_count < 1) {
                std::cout << "Unexpected input data. Correct input file.";
                return 0;
            }
            else {
                readFile(input_file, arr_of_addresses, addresses_count);
                input_file.close();

                std::ofstream output_file;
                output_file.open("out.txt");

                output_file << addresses_count;

                std::sort(arr_of_addresses, arr_of_addresses + addresses_count, comp);
                    
                for (int i = 0; i < addresses_count; ++i) {

                    output_file << "\n" << arr_of_addresses[i]->getOutputAddress();
                    delete arr_of_addresses[i];     // сразу удаляю под массив чтобы не создавать для этого еще новый цикл
                }
                output_file.close();
                delete[] arr_of_addresses;
                arr_of_addresses = nullptr;
            }
        }
        else {
            std::cout << "Unexpected end of the input file";
            return 0;
        }
    }

    return 0;
}