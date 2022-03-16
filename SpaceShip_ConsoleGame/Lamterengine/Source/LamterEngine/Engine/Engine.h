#pragma once

#include "Time.h"
#include "../Structures/IGame.h"
#include "../Classes/COORD.h"
#include "../Structures/IMenu.h"

namespace Lamter
{
	class Engine
	{
	private:
		Time* gameTime;
		IGame* game;
		IMenu* menu;
		bool exitGame = false;

	public:
		Engine(IMenu* _menu, IGame* _game, int targetFPS, COORD consoleBufferSize, bool showCursor);
		~Engine();
		void Run();
	};

}

