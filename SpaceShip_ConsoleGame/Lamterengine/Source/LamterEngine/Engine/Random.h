#pragma once

#include "../Classes/COORD.h"

namespace Lamter
{
	class Random
	{
	private:
		static char* abecedary;


	public:
		Random() = delete;

		static int GetRandomNumberInRange(int min, int max);
		static char GetRandomLetter();
		static void SetSeed(int seed);
		static void Init();
		static int GetRandomNumber();
		static COORD GetRandomCoord(short minX, short minY, short maxX, short maxY);

	private:

	};
}

