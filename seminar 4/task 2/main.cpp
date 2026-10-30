#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>

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

int sumLess43(int sum, int value)
{
	if (std::abs(value) < 43)
	{
		return sum + value;
	}
	return sum;
}

std::vector<int> findRepeated(const std::vector<int>& vec, int minCount)
{
	std::vector<int> res;
	for (int value : vec)
	{
		if (std::find(res.begin(), res.end(), value) != res.end())
		{
			continue;
		}
		int counter = std::count(vec.begin(), vec.end(), value);
		if (counter >= minCount)
		{
			res.push_back(value);
		}
	}
	return res;
}

void compareWithFor(const std::vector<int>& first, const std::vector<int>& second, const std::vector<int>& repeatedSecond)
{
	std::cout << "\nПодсчет циклом for:\n";
	for (int value : repeatedSecond)
	{
		int countFirst = 0;
		for (int x : first)
		{
			if (x == value)
			{
				++countFirst;
			}
		}
		if (countFirst > 3)
		{
			int countSecond = 0;
			for (int x : second)
			{
				if (x == value)
				{
					++countSecond;
				}
			}
			std::cout << value << " -> в первом векторе: " << countFirst << ", во втором векторе: " << countSecond << "\n";
		}
	}
}

void compareWithAlgorithm(const std::vector<int>& first, const std::vector<int>& second, const std::vector<int>& repeatedSecond)
{
	std::cout << "\nПодсчет через std::for_each с лямбдой:\n";
	std::for_each(repeatedSecond.begin(), repeatedSecond.end(), [&](int value)
	{
		int countFirst = std::count(first.begin(), first.end(), value);
		if (countFirst > 3)
		{
			int countSecond = std::count(second.begin(), second.end(), value);
			std::cout << value << " -> в первом векторе: " << countFirst << ", во втором векторе: " << countSecond << "\n";
		}
	});
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

	int firstSum = std::accumulate(first.begin(), first.end(), 0, sumLess43);
	int secondSum = std::accumulate(second.begin(), second.end(), 0, sumLess43);

	std::cout << "\nРезультат бинарной операции (сумма чисел с |x| < 43):\n";
	std::cout << "первый вектор: " << firstSum << "\n";
	std::cout << "второй вектор: " << secondSum << "\n";

	std::vector<int> repeatedSecond = findRepeated(second, 2);
	std::vector<int> repeatedFirst = findRepeated(first, 4);

	std::cout << "\nЧисла второго вектора, встречающиеся 2 и более раз:\n";
	for (int value : repeatedSecond)
	{
		std::cout << value << " ";
	}
	std::cout << "\n";

	std::cout << "\nЧисла первого вектора, встречающиеся более 3 раз:\n";
	for (int value : repeatedFirst)
	{
		std::cout << value << " ";
	}
	std::cout << "\n";

	compareWithFor(first, second, repeatedSecond);
	compareWithAlgorithm(first, second, repeatedSecond);

	return 0;
}
