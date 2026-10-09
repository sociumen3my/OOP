#include <iostream>
#include <memory>

int main()
{
	int x = 10;
	int* raw = new int{x};
	delete raw;
	std::cout << *raw << " dangling pointer (UB)\n";
	raw = nullptr;

	auto p1 = std::make_unique<int>(x);
	std::cout << "p1 = " << *p1 << "\n";

	auto p2 = std::make_unique<int[]>(9);
	for (int i = 0; i < 9; i++)
	{
		p2[i] = i + 1;
	}
	for (int i = 0; i < 9; i++)
	{
		std::cout << p2[i] << "\n";
	}

	p1.reset();
	std::cout << "p1 = " << (p1 ? "valid" : "nullptr, no dangling") << "\n";

	auto p3 = std::make_unique<int[]>(10);
	for (int i = 0; i < 4; i++)
	{
		p3[i] = p2[i];
	}
	p3[4] = 121;
	for (int i = 4; i < 9; i++)
	{
		p3[i + 1] = p2[i];
	}

	p2 = std::move(p3);
	std::cout << "p3 = " << (p3 ? "valid" : "nullptr, no dangling") << "\n";

	for (int i = 0; i < 10; i++)
	{
		std::cout << p2[i] << "\n";
	}
}
