#include <iostream>
#include <string>
#include <fstream>

void SplitStr(std::string str, int* arr, int size)
{
	int i = 0;
	std::string s = "";
	for (auto x : str)
	{
		if (x == ' ')
		{
			arr[i] = std::stoi(s);
			++i;
			s = "";
		}
		else {
			s = s + x;
		}
	}
	arr[i] = std::stoi(s);

	if (++i != size) {
		std::cout << "Input data incorrect.";
		std::exit(0);
	}
}

int* readFile(std::ifstream& input_file, int& size) {
	std::string str;
	getline(input_file, str);
	if (!input_file.eof()) {
		size = std::stoi(str);
		if (size <= 0) {

			std::cout << "Array Length must be greater than zero.";
			std::exit(0);
		}
	}
	else {

		std::cout << "Unexpected end of file. Correct input data.";
		std::exit(0);
	}


	int* arr = new int[size];
	getline(input_file, str);
	SplitStr(str, arr, size);
	return arr;
}

void releaseArrayMem(int** array_ptr, int size)
{
	delete[] * array_ptr;
	*array_ptr = nullptr;
}

void copyArray(int* arr1, int* arr2, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr1[i] = arr2[i];
	}
}

void shiftArr(int* arr, int size, int shift) {

	int* temp = new int[size];
	int j = 0;

	shift > 0 ?
		j = abs(size - shift) :	
		j = abs(shift);
	
	if (j >= size) {
		j = 0;
	}

	for (int i = 0; i < size; ++i) {

		temp[i] = arr[j];

		if (++j >= size) {
			j = 0;
		}
	}
	copyArray(arr, temp, size);
	releaseArrayMem(&temp, size);
}

int main()
{
	std::ifstream input_file;

	int arr1_size = 0;
	int arr2_size = 0;

	input_file.open("in.txt");

	if (input_file.is_open()) {
		//	задача считать 2 массива из входного файла
		int* arr1 = readFile(input_file, arr1_size);	// начинаем читать файл и заполняем первый массив
		int* arr2 = readFile(input_file, arr2_size);	// продолжаем читать файл дальше и заполняем второй массив

		input_file.close();

		std::ofstream output_file("out.txt");

		if (output_file.is_open()) {

			output_file << arr2_size;
			output_file << "\n";

			shiftArr(arr2, arr2_size, 1);	// сдвигаем массив на 1 вправо

			for (int i = 0; i < arr2_size; ++i) {
				output_file << arr2[i];
				output_file << " ";
			}

			output_file << "\n";
			output_file << arr1_size;
			output_file << "\n";

			shiftArr(arr1, arr1_size, -1);	// сдвигаем массив на 1 влево

			for (int i = 0; i < arr1_size; ++i) {
				output_file << arr1[i];
				output_file << " ";
			}

			output_file.close();
			releaseArrayMem(&arr1, arr1_size);
			releaseArrayMem(&arr2, arr2_size);
		}
	}

	return 0;
}