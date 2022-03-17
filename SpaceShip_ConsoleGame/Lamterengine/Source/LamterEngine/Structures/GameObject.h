#pragma once

#include <string>

#include "Object.h"
#include "../Classes/COORD.h"

namespace Lamter
{
	class GameObject : Object
	{
	public:
		Lamter::COORD position = { 0,0 };
		std::string tag = "";

	public:
		virtual ~GameObject() = default;
		virtual void Awake() = 0;
		virtual void Update(double dt) = 0;
		virtual void DrawnUpdate() = 0;
		virtual void Draw() = 0;
	};
}

