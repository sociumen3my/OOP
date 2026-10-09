#include <random>

namespace moddified
{
	template <typename T1, typename T2>
	T2 area(const T1& x, const T1& y)
	{
		T2 res = x * y;
		std::random_device rd;
		std::mt19937 generator(rd());
		std::uniform_int_distribution<int>chance(0, 1);
		if (chance(generator) == 1)
		{
			std::uniform_int_distribution<int> randomNumber(1, 10);
			res = res + randomNumber(generator);
		}
		return res;
	}
}
