#include "area2.h"
#include <random>

namespace moddified
{
    int area(int x, int y)
    {
        int res = x * y;
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> chance(0, 1);

        if (chance(generator) == 1)
        {
            std::uniform_int_distribution<int> randomNumber(1, 10);
            res = res + randomNumber(generator);
        }

        return res;
    }
}
