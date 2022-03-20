#pragma once
#include <vector>

#include "GameObject.h"

namespace Lamter
{
	class Game
	{
	public:
		bool exitGame = false;
		std::vector<GameObject*>* gameObjects;

	private:
		static bool DrawOrder(GameObject* object1, GameObject* object2);

	public:
		Game();
		virtual ~Game();
		
		virtual void Init();
		virtual void NewGame() = 0;
		virtual void AddGameObject(GameObject* _gameObject);
		virtual void DestroyGameObject(GameObject* gameObject);

		virtual void CollisionCheck();
		virtual void Update(double dt);
		virtual void DrawnUpdate();
		virtual void Draw();

		/**
		 * \brief controls game loop
		 * \return true if game is finished, false  otherwise
		 */
		virtual bool ExitLoop();
	};
}

