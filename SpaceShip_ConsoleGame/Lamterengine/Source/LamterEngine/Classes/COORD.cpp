#include "COORD.h"

namespace Lamter
{
	COORD::COORD(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	COORD::COORD(short _x, short _y)
	{
		x = _x;
		y = _y;
	}

	COORD& COORD::operator+=(const COORD& rhs)
	{
		this->x = x + rhs.x;
		this->y = y + rhs.y;
		return *this;
	}

	COORD& COORD::operator-=(const COORD& rhs)
	{
		this->x = x - rhs.x;
		this->y = y - rhs.y;
		return *this;
	}

	COORD& COORD::operator/=(const COORD& rhs)
	{
		this->x = this->x / rhs.x;
		this->y = this->y / rhs.y;
		return *this;
	}

	COORD& COORD::operator*=(const COORD& rhs)
	{
		this->x = this->x * rhs.x;
		this->y = this->y * rhs.y;
		return *this;
	}

	bool COORD::operator!=(const COORD& rhs)
	{
		return this->x != rhs.x || this->y != rhs.y;
	}

	bool COORD::operator==(const COORD& rhs)
	{
		return this->x == rhs.x && this->y == rhs.y;
	}

	COORD COORD::operator+(const COORD& rhs)
	{
		COORD temp;
		temp.x = this->x + rhs.x;
		temp.y = this->y + rhs.y;
		return temp;
	}

	COORD COORD::operator-(const COORD& rhs)
	{
		COORD temp;
		temp.x = this->x - rhs.x;
		temp.y = this->y - rhs.y;
		return temp;
	}

	COORD COORD::operator*(const COORD& rhs)
	{
		COORD temp;
		temp.x = this->x * rhs.x;
		temp.y = this->y * rhs.y;
		return temp;
	}

	COORD COORD::operator/(const COORD& rhs)
	{
		COORD temp;
		temp.x = this->x / rhs.x;
		temp.y = this->y / rhs.y;
		return temp;
	}
}
