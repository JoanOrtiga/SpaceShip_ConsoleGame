#include "Engine.h"

#include "Random.h"
#include "../Input/InputManager.h"
#include "../Console/ConsoleController.h"


namespace Lamter
{
	Engine::Engine(IMenu* _menu, Game* _game, int targetFPS, COORD consoleBufferSize, bool showCursor) : gameTime(new Time(targetFPS))
	{
		ConsoleController::Init(consoleBufferSize, showCursor);
		InputManager::Init();
		Random::Init();

		menu = _menu;
		game = _game;
		game->Init();
	}

	void Engine::Run()
	{
		while(!menu->ExitGame())
		{
			while (!game->ExitLoop())
			{
				InputManager::UpdateInput();

				bool normalUpdate;
				const bool shouldDraw = gameTime->ShouldDrawNextFrame(normalUpdate);

				if (normalUpdate)
				{
					game->Update(gameTime->deltaSeconds);
				}

				if (shouldDraw)
				{
					game->DrawnUpdate();
					if (game->ExitLoop())
						break;
					game->Draw();
				}

				if (InputManager::IsKeyDown(KeyCode::Escape))
				{
					exitGame = true;
					break;
				}
			}

			menu->Update();
			menu->Draw();
		}
	}

	Engine::~Engine()
	{
		delete game;
		delete gameTime;
	}
}
