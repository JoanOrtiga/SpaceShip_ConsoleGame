#pragma once

#include "Time.h"
#include "../Structures/Game.h"
#include "../Classes/COORD.h"
#include "../Structures/IMenu.h"

namespace Lamter
{
	class Engine
	{
	private:
		Time* gameTime;
		Game* game;
		IMenu* menu;
		bool exitGame = false;

	public:
		Engine(IMenu* _menu, Game* _game, int targetFPS, COORD consoleBufferSize, bool showCursor);
		~Engine();
		void Run();
	};

}

