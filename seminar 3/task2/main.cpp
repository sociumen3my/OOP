#include <iostream>

int main()
{
	int x = 10;
	int* p1 = new int{x};

	int* p2{ new int[9] {1, 2, 3, 4, 5, 6, 7, 8, 9} };
	for (int i = 0; i < 9; i++)
	{
		std::cout << *(p2 + i) << "\n";
	}

	delete p1;
	std::cout << *(p1) << " visyachiy ukazatel\n";
	p1 = nullptr; 
	delete p1;

	int* p3 = new int[10];
	for (int i = 0; i < 4; i++)
	{
		p3[i] = p2[i];
	}
	p3[4] = 121;
	for (int i = 4; i < 9; i++)
	{
		p3[i + 1] = p2[i];
	}

	delete[] p2;
	p2 = p3;
	p3 = nullptr;

	for (int i = 0; i < 10; i++)
	{
		std::cout << *(p2 + i) << "\n";
	}

	delete[] p2;
	p2 = nullptr;
}