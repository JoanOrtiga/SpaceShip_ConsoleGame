#pragma once

#include "../Classes/COORD.h"

namespace Lamter
{
	class Collider
	{
	public:
		virtual ~Collider() = default;
		virtual bool IsColliding(COORD _position) = 0;
	};
}

