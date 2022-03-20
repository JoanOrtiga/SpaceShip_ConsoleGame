#pragma once

#include <string>

#include "Object.h"
#include "../Classes/COORD.h"
#include "Game.fwd.h"

namespace Lamter
{
	class GameObject : Object
	{
	public:
		int orderInLayer = 0;
		Lamter::COORD position = { 0,0 };
		std::string tag;
		Game* game;

	protected:
		GameObject(Game* _game);

	public:
		virtual ~GameObject() = default;
		virtual void Awake() = 0;
		virtual void NewGame() = 0;
		virtual void Update(double dt) = 0;
		virtual void DrawnUpdate() = 0;
		virtual void Draw() = 0;
	};
}

