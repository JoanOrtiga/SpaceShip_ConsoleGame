#include "Engine.h"

#include "Random.h"
#include "../Input/InputManager.h"
#include "../Console/ConsoleController.h"


namespace Lamter
{
	Engine::Engine(Menu* _menu, Game* _game, int targetFPS, COORD consoleBufferSize, bool showCursor) : gameTime(new Time(targetFPS)),
		game(_game), menu(_menu)
	{
		ConsoleController::Init(consoleBufferSize, showCursor);
		InputManager::Init();
		Random::Init();
	}

	void Engine::Run()
	{
		game->Init();

		while(!menu->ExitGame())
		{
			while (!game->ExitLoop())
			{
				InputManager::UpdateInput();

				game->AddObjectsFromQueue();
				game->DestroyObjectsFromQueue();

				bool normalUpdate;
				const bool shouldDraw = gameTime->ShouldDrawNextFrame(normalUpdate);

				if (normalUpdate)
				{
					game->Update(gameTime->deltaSeconds);
				}

				if (shouldDraw)
				{
					game->DrawnUpdate();
					game->CollisionCheck();
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

			menu->InitialDraw();

			while (!menu->ExitMenu())
			{
				menu->Update();
				menu->Draw();
			}

			menu->ResetMenu();
		}
	}

	Engine::~Engine()
	{
		InputManager::Delete();
		delete game;
		delete gameTime;
	}
}
