#include "Random.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

namespace Lamter
{
	#define ALPHABET_LENGTH 26
	char* Random::abecedary = new char[]
	{
		"QWERTYUIOPASDFGHJKLZXCVBNM"
	};

	void Random::Init()
	{
		srand(time(nullptr));
	}

	int Random::GetRandomNumber()
	{
		return rand();
	}

	COORD Random::GetRandomCoord(short minX, short minY, short maxX, short maxY)
	{
		short x = GetRandomNumberInRange(minX, maxX);
		short y = GetRandomNumberInRange(minY, maxY);
		return { x, y };
	}

	int Random::GetRandomNumberInRange(int min, int max)
	{
		return min + (rand() % (int)(max - min + 1));
	}

	char Random::GetRandomLetter()
	{
		return abecedary[rand() % ALPHABET_LENGTH];
	}

	void Random::SetSeed(int seed)
	{
		srand(seed);
	}
}


