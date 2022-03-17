#pragma once
#include <vector>

#include "GameObject.h"

namespace Lamter
{
	class Game
	{
	public:
		bool exitGame = false;
		std::vector<Lamter::GameObject>* gameObjects;

	public:
		virtual ~Game();
		/**
		 * \brief controls game loop
		 * \return true if game is finished, false  otherwise
		 */
		virtual void Init();
		void AddGameObject(GameObject* _gameObject);
		virtual void NewGame() = 0;
		virtual void DestroyGameObject(GameObject* gameObject);
		virtual bool ExitLoop();
		virtual void Update(double dt);
		virtual void DrawnUpdate();
		virtual void Draw();
	};
}

