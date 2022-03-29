#pragma once

#include <map>
#include <unordered_map>
#include <vector>

#include "Collider.h"
#include "GameObject.h"

#include "../XMLParser/ILoadable.h"
#include "../XMLParser/ISavable.h"

namespace Lamter
{
	class Game : public ISavable, public ILoadable
	{
	private:
		std::unordered_map<Collider*, GameObject*> references;
		std::vector<Collider*> colliders;
		std::multimap<Collider*, Collider*> collisionsDone;

	public:
		bool exitGame = false;
		std::vector<GameObject*>* gameObjects;
		std::vector<GameObject*>* addGameObjectsQueue;
		std::vector<GameObject*>* destroyGameObjectsQueue;

	private:
		static bool DrawOrder(GameObject* object1, GameObject* object2);

	public:
		Game();
		virtual ~Game();
		
		virtual void Init();
		virtual void NewGame()
		{
			exitGame = false;
		};
		virtual void AddGameObject(GameObject* _gameObject);
		virtual void AddGameObjectImmediate(GameObject* _gameObject);
		virtual void DestroyGameObject(GameObject* gameObject);
		virtual void DestroyGameObjectImmediate(GameObject* _gameObject);
		virtual void AddObjectsFromQueue();
		virtual void DestroyObjectsFromQueue();

		virtual void CollisionCheck();
		virtual void Update(double dt);
		virtual void DrawnUpdate();
		virtual void Draw();

		/**
		 * \brief controls game loop
		 * \return true if game is finished, false  otherwise
		 */
		virtual bool ExitLoop();
		virtual void EndGame() = 0;

		virtual void SaveAllGame(std::string fileLocation);
		virtual void LoadAllGame(std::string fileLocation);
		virtual void SaveGameObject(GameObject* gameObject, std::string fileLocation);
		virtual void LoadGameObject(GameObject* gameObject, std::string fileLocation);
		void LoadFromFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* rootNode) override;
		void SaveToFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* rootNode) override;
	};
}

