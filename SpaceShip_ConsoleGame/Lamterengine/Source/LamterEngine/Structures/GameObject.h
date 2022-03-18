#pragma once

#include <string>

#include "Object.h"
#include "../Classes/COORD.h"

namespace Lamter
{
	class GameObject
	{
	public:
		Lamter::COORD position = { 0,0 };
		std::string tag;

	public:
		virtual ~GameObject() = default;
		virtual void Awake();
		virtual void Update(double dt);
		virtual void DrawnUpdate();
		virtual void Draw();
	};
}

