#pragma once

#include "Game.fwd.h"

namespace Lamter
{
	class Menu
	{
	protected:
		bool exitMenu = false;
		Game* game;
	public:
		Menu(Game* _game) : exitMenu(false), game(_game)
		{
		}
		virtual ~Menu() = default;
		virtual bool ExitGame()
		{
			return exitMenu;
		}
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void InitialDraw() = 0;
	};
}


