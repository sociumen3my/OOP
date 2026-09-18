#include <iostream>
#include "area.h"
#include "area2.h"

int main() 
{
	int x;
	int y;
	double z;

	std::cout << "enter x\n";
	std::cin >> x;
	std::cout << "enter y\n";
	std::cin >> y;
	std::cout << "enter z\n";
	std::cin >> z;

	std::cout << "area (int -> double):"
			  << standart::area<double, int>(x, y) // a
			  << "\n";

	std::cout << "area mod (int -> double): "
			  << moddified::area<double, int>(x, y)
			  << "\n";

	std::cout << "area (double -> int): "	
			  << standart::area<int, double>(z, z)	// b
			  << "\n";

	std::cout << "area mod (double -> int): " 
			  << moddified::area<int, double>(z, z)
		      << "\n";
	
	return 0;
}