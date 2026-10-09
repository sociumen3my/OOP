#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <fstream>
#include <random>
#include <sstream>
#include <iomanip>
#include "area2.h"

int main()
{
	const int M = 13;
	const int N = 3000;

	std::mt19937 gen(std::random_device{}());
	std::uniform_int_distribution<int> dist(-N, N);

	std::array<int, M> cArray;
	std::vector<int> cVector;
	std::list<int> cList;
	std::deque<int> cDeque;

	for (int i = 0; i < M; i++)
	{
		cArray[i] = dist(gen);
		cVector.push_back(dist(gen));
		cList.push_back(dist(gen));
		cDeque.push_back(dist(gen));
	}

	int y = dist(gen);
	std::cout << "y = " << y << "\n";

	std::vector<float> resVec;
	std::list<float> resList;
	std::deque<float> resDeque;
	std::array<float, M> resArr;

	for (int i = 0; i < M; i++)
	{
		resVec.push_back(moddified::area<int, float>(cArray[i], y));
	}

	for (auto it = cVector.begin(); it != cVector.end(); ++it)
	{
		resList.push_back(moddified::area<int, float>(*it, y));
	}

	for (int v : cList)
	{
		resDeque.push_back(moddified::area<int, float>(v, y));
	}

	for (int i = 0; i < M; i++)
	{
		resArr[i] = moddified::area<int, float>(cDeque[i], y);
	}

	std::vector<int> cListVec;
	for (int v : cList)
	{
		cListVec.push_back(v);
	}

	std::vector<float> resListVec;
	for (float v : resList)
	{
		resListVec.push_back(v);
	}

	std::vector<std::string> rows;
	for (int i = 0; i < M; i++)
	{
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(1);
		oss << cArray[i] << " | " << cVector[i] << " | " << cListVec[i] << " | "
			<< cDeque[i] << " | " << resVec[i] << " | " << resListVec[i] << " | "
			<< resDeque[i] << " | " << resArr[i];
		rows.push_back(oss.str());
	}

	std::ofstream out("table.md");
	out << "| array | vector | list | deque | array->vector | vector->list | list->deque | deque->array |\n";
	out << "| --- | --- | --- | --- | --- | --- | --- | --- |\n";
	for (int i = 0; i < M; i++)
	{
		out << "| " << rows[i] << " |\n";
	}

	std::cout << "table.md written\n";
}
