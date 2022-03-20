#pragma once

#include "Time.h"
#include "../Structures/Game.h"
#include "../Classes/COORD.h"
#include "../Structures/Menu.h"

namespace Lamter
{
	class Engine
	{
	private:
		Time* gameTime;
		Game* game;
		Menu* menu;
		bool exitGame = false;

	public:
		Engine(Menu* _menu, Game* _game, int targetFPS, COORD consoleBufferSize, bool showCursor);
		~Engine();
		void Run();
	};

}

