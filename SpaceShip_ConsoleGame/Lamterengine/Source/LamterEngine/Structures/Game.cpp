#include "Game.h"

#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>


#include "Collider.h"
#include "../Console/ConsoleController.h"
#include "../XMLParser/XMLManager.h"

namespace Lamter
{
	Game::Game() : gameObjects(new std::vector<Lamter::GameObject*>()), addGameObjectsQueue(new std::vector<Lamter::GameObject*>()),
	destroyGameObjectsQueue(new std::vector<Lamter::GameObject*>())
	{

	}

	Game::~Game()
	{
		delete gameObjects;
		delete addGameObjectsQueue;
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
		addGameObjectsQueue->push_back(_gameObject);
	}

	void Game::AddGameObjectImmediate(GameObject* _gameObject)
	{
		gameObjects->push_back(_gameObject);
		_gameObject->Awake();
	}

	void Game::DestroyGameObject(GameObject* _gameObject)
	{
		for(auto gameObject : *gameObjects)
		{
			if(_gameObject == gameObject)
			{
				destroyGameObjectsQueue->push_back(gameObject);
			}
		}
	}

	void Game::DestroyGameObjectImmediate(GameObject* _gameObject)
	{
		for (auto gameObject : *gameObjects)
		{
			if (_gameObject == gameObject)
			{
				gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gameObject), gameObjects->end());

				Collider* collider;
				if(Collider::TryGetCollider(gameObject, collider))
				{
					colliders.erase(std::remove(colliders.begin(), colliders.end(), collider), colliders.end());
					//colliders.push_back(collider);
					references.erase(collider);
				}

				delete gameObject;
			}
		}
	}

	void Game::AddObjectsFromQueue()
	{
		for(auto gameObject : *addGameObjectsQueue)
		{
			gameObjects->push_back(gameObject);
		}
		for(auto gameObject : *addGameObjectsQueue)
		{
			gameObject->Awake();
		}

		addGameObjectsQueue->clear();
	}

	void Game::DestroyObjectsFromQueue()
	{
		for (auto destroyElement : *destroyGameObjectsQueue)
		{
			for (auto gameObject : *gameObjects)
			{
				if (destroyElement == gameObject)
				{
					gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gameObject), gameObjects->end());
					delete gameObject;
				}
			}
		}
		destroyGameObjectsQueue->clear();
	}

	void Game::CollisionCheck()
	{
		for (auto& gameObject : *gameObjects)
		{
			Collider* collider = nullptr;
			if (Collider::TryGetCollider(gameObject, collider))
			{
				references.insert({collider, gameObject});
				colliders.push_back(collider);
			}
		}


		for(short i = 0; i < colliders.size(); ++i)
		{
			for (short e = 0; e < colliders.size(); ++e)
			{
				if (i == e)
					continue;
				bool skip = false;
				for (auto itr = collisionsDone.begin(); itr != collisionsDone.end(); ++itr)
				{
					if(itr->first == colliders[e])
					{
						if (itr->second == colliders[i])
							skip = true;
					}
				}
				if (skip)
					continue;
				if (colliders[i] == nullptr || colliders[e] == nullptr ||references[colliders[i]] == nullptr || references[colliders[e]] == nullptr)
					continue;
				auto collided = colliders[i]->IsColliding(*(references[colliders[i]]), *(references[colliders[e]]), colliders[e]);

				if (e >= colliders.size())
					continue;
				if(collided)
				{
					if(i < colliders.size() ||e < colliders.size())
						collisionsDone.insert(std::pair<Collider*, Collider*>(colliders[i], colliders[e]));
				}
			}
		}

		references.clear();
		colliders.clear();
		collisionsDone.clear();
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

	void Game::SaveAllGame(std::string fileLocation)
	{
		Lamter::XMLManager::SaveGame(this, fileLocation);
	}

	void Game::LoadAllGame(std::string fileLocation)
	{
		Lamter::XMLManager::LoadGame(this, fileLocation);
	}

	void Game::SaveGameObject(GameObject* gameObject, std::string fileLocation)
	{
		XMLManager::SaveGameObject(gameObject, fileLocation);
	}

	void Game::LoadGameObject(GameObject* gameObject, std::string fileLocation)
	{
		XMLManager::LoadGameObject(gameObject, fileLocation);
	}

	void Game::LoadFromFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLElement* rootNode)
	{
		for (auto gameObject : *gameObjects)
		{
			gameObject->LoadFromFile(doc, rootNode);
		}
	}

	void Game::SaveToFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLElement* rootNode)
	{
		for (auto gameObject : *gameObjects)
		{
			gameObject->SaveToFile(doc, rootNode);
		}
	}
}

