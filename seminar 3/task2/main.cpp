#include <iostream>

int main()
{
	int x = 10;
	int* p1{ new int{x} };

	int* p2{ new int[9] {1, 2, 3, 4, 5, 6, 7, 8} };
	for (int i = 0; i < 9; i++)
	{
		std::cout << *(p2 + i) << "\n";
	}

	delete p1;
	std::cout << *(p1) << "vis \n";
	
	p2[4] = 67;

	for (int i = 0; i < 9; i++)
	{
		std::cout << *(p2 + i) << "\n";
	}

	p1 = nullptr; 
	delete p2;
	p2 = nullptr;
}