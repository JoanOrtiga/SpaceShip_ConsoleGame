#pragma once

#include "Game.h"

#include "../Console/ConsoleController.h"

namespace Lamter
{
	class Menu
	{
	protected:
		bool exitMenu = false;
		bool exitGame = false;
		Game* game;
	public:
		Menu(Game* _game) : exitMenu(false), game(_game)
		{
		}
		virtual ~Menu() = default;
		virtual bool ExitMenu()
		{
			return exitMenu;
		}
		virtual bool ExitGame()
		{
			return exitGame;
		}
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void InitialDraw() = 0;
		virtual void Quit()
		{
			exitGame = true;
			exitMenu = true;
		}
		virtual void NewGame()
		{
			game->NewGame();
			exitMenu = true;
		}
		virtual void ResetMenu()
		{
			Lamter::ConsoleController::CLS();
			exitMenu = false;
		}
	};
}


