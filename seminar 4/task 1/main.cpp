#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

std::vector<int> readFile(const std::string& filename)
{
	std::ifstream file(filename);
	std::vector<int> numbers;

	int number;
	while (file >> number)
	{
		numbers.push_back(number);

		if (file.peek() == ',')
		{
			file.ignore();
		}
	}
	return numbers;
}

void countFor(const std::vector<int>& vec)
{
	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		bool repeated = false;

		for (std::size_t j = 0; j < i; ++j)
		{
			if (vec[i] == vec[j])
			{
				repeated = true;
				break;
			}
		}
		if (repeated)
		{
			continue;
		}
		int counter = 0;
		for (int value : vec)
		{
			if (value == vec[i])
			{
				++counter;
			}
		}
		std::cout << vec[i] << " -> " << counter << "\n";
	}
}

void countAlgorithm(const std::vector<int>& vec)
{
	std::vector<int> used;
	for (int value : vec)
	{
		if (std::find(used.begin(), used.end(), value) != used.end())
		{
			continue;
		}
		int counter = std::count(vec.begin(), vec.end(), value);
		std::cout << value << " -> " << counter << "\n";
		used.push_back(value);
	}
}

int main()
{
	std::vector<int> first = readFile("../s04_v1_43_1.txt");
	std::vector<int> second = readFile("../s04_v1_43_2.txt");

	if (first.size() < second.size())
	{
		std::swap(first, second);
	}

	std::cout << "Чисел в первом векторе: " << first.size() << "\n";
	std::cout << "Чисел во втором векторе: " << second.size() << "\n";

	std::cout << "\nЧастоты первого вектора (цикл for):\n";
	countFor(first);
	std::cout << "\nЧастоты второго вектора (цикл for):\n";
	countFor(second);

	std::cout << "\nЧастоты первого вектора (std::count):\n";
	countAlgorithm(first);
	std::cout << "\nЧастоты второго вектора (std::count):\n";
	countAlgorithm(second);

	int firstSum1 = std::accumulate(first.begin(), first.end(), 0);
	int secondSum1 = std::accumulate(second.begin(), second.end(), 0);
	std::cout << "\nСумма всех элементов через std::accumulate:\n";
	std::cout << "первый вектор: " << firstSum1 << "\n";
	std::cout << "второй вектор: " << secondSum1 << "\n";

	int firstSum2 = std::reduce(first.begin(), first.end(), 0);
	int secondSum2 = std::reduce(second.begin(), second.end(), 0);
	std::cout << "\nСумма всех элементов через std::reduce:\n";
	std::cout << "первый вектор: " << firstSum2 << "\n";
	std::cout << "второй вектор: " << secondSum2 << "\n";

	int first10 = std::accumulate(first.begin(), first.begin() + 10, 0);
	int second10 = std::accumulate(second.begin(), second.begin() + 10, 0);
	std::cout << "\nСумма первых 10 элементов (без циклов):\n";
	std::cout << "первый вектор: " << first10 << "\n";
	std::cout << "второй вектор: " << second10 << "\n";

	return 0;
}
