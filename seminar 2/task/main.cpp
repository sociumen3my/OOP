#include <iostream>
#include "area.h"
#include "area2.h"

int main() 
{
	int x;
	int y;

	std::cout << "enter x";
	std::cin >> x;
	std::cout << "enter y";
	std::cin >> y;

	std::cout << "area: "
			  << standart::area(x, y)
			  << "\n";

	std::cout << "area mod: "
			  << moddified::area(x, y)
		      << "\n";

	return 0;
}