#include <iostream>
#include "area.h"
#include "area2.h"

int main()
{
	int x, y;
	double z, d;

	std::cout << "enter x (int)\n";
	std::cin >> x;
	std::cout << "enter y (int)\n";
	std::cin >> y;
	std::cout << "enter z (double)\n";
	std::cin >> z;
	std::cout << "enter d (double)\n";
	std::cin >> d;

	std::cout << "area (int -> double):"
			  << standart::area<int, double>(x, y) // a
			  << "\n";

	std::cout << "area mod (int -> double):"
			  << moddified::area<int, double>(x, y) // a
			  << "\n";

	std::cout << "area (double -> int):"
			  << standart::area<double, int>(z, d) // b
			  << "\n";

	std::cout << "area mod (int -> double):"
			  << moddified::area<double, int>(z, d) // b
			  << "\n";
		
	return 0;
}
