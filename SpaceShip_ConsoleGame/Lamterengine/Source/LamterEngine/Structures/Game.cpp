#include "Game.h"

#include <algorithm>
#include <map>
#include <unordered_map>


#include "Collider.h"

namespace Lamter
{
	Game::Game() : gameObjects(new std::vector<Lamter::GameObject*>())
	{
	}

	Game::~Game()
	{
		delete gameObjects;
	}

	void Game::Init()
	{
		for (auto gameObject : *gameObjects)
		{
			gameObject->Awake();
		}
	}

	void Game::AddGameObject(GameObject* _gameObject)
	{
		gameObjects->push_back(_gameObject);
	}

	void Game::NewGame()
	{
	}

	void Game::DestroyGameObject(GameObject* _gameObject)
	{
		for(auto gameObject : *gameObjects)
		{
			if(_gameObject == gameObject)
			{
				gameObjects->push_back(gameObject);
				delete gameObject;
			}
		}
	}

	
	void Game::CollisionCheck()
	{
		std::unordered_map<Collider*, GameObject*> references;
		std::vector<Collider*> colliders;
		for (short e = 0; e < gameObjects->size(); ++e)
		{
			Collider* collider = nullptr;
			if (Collider::TryGetCollider((*gameObjects)[e], collider))
			{
				references.insert({collider, (*gameObjects)[e] });
				colliders.push_back(collider);
			}
		}

		for(short i = 0; i < colliders.size(); ++i) //2
		{
			for (short e = 0; e < colliders.size(); ++e) //
			{
				if (i == e)
					continue;
				colliders[i]->IsColliding(*(references[colliders[i]]), *(references[colliders[e]]));
			}
		}
	}

	bool Game::ExitLoop()
	{
		return exitGame;
	}

	void Game::Update(double dt)
	{
		for (auto gameObject : *gameObjects)
		{
			gameObject->Update(dt);
		}
	}

	void Game::DrawnUpdate()
	{
		for (auto gameObject : *gameObjects)
		{
			gameObject->DrawnUpdate();
		}
	}

	void Game::Draw()
	{
		std::sort(gameObjects->begin(), gameObjects->end(), DrawOrder);

		for (auto gameObject : *gameObjects)
		{
			gameObject->Draw();
		}
	}

	bool Game::DrawOrder(GameObject* object1, GameObject* object2)
	{
		return object1->orderInLayer < object2->orderInLayer;
	}
}

