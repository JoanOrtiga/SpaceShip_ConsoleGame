#pragma once

namespace Lamter
{
	typedef struct COORD
	{
		short x;
		short y;

		COORD() = default;
		COORD(int _x, int _y);
		COORD(short _x, short _y);

		COORD& operator+=(const COORD& rhs);
		COORD& operator-=(const COORD& rhs);
		COORD& operator/=(const COORD& rhs);
		COORD& operator*=(const COORD& rhs);
		bool operator!=(const COORD& rhs);
		bool operator==(const COORD& rhs);
		COORD operator+(const COORD& rhs);
		COORD operator-(const COORD& rhs);
		COORD operator*(const COORD& rhs);
		COORD operator/(const COORD& rhs);
	};
}

