#include "Game.h"

namespace Lamter
{
	/*Game::~Game()
	{
		delete gameObjects;
	}*/

	void Game::Init()
	{
		gameObjects = new std::vector<Lamter::GameObject>();
	}

	void Game::AddGameObject(GameObject* _gameObject)
	{
		gameObjects->push_back(*_gameObject);
		_gameObject->Awake();
	}

	void Game::NewGame()
	{
	}

	void Game::DestroyGameObject(GameObject* _gameObject)
	{
		for(auto& gameObject : *gameObjects)
		{
			if(_gameObject == (&gameObject))
			{
				gameObjects->push_back(gameObject);
				delete &gameObject;
			}
		}
	}

	bool Game::ExitLoop()
	{
		return exitGame;
	}

	void Game::Update(double dt)
	{
		for (auto& gameObject : *gameObjects)
		{
			gameObject.Update(dt);
		}
	}

	void Game::DrawnUpdate()
	{
		for (auto& gameObject : *gameObjects)
		{
			gameObject.DrawnUpdate();
		}
	}

	void Game::Draw()
	{
		for (auto& gameObject : *gameObjects)
		{
			gameObject.Draw();
		}
	}
}

