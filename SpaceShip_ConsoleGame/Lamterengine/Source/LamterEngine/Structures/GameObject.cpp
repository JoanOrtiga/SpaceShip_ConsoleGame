#include "GameObject.h"

#include "Game.h"

namespace Lamter
{
	GameObject::GameObject(Game* _game) : game(_game)
	{
		game->AddGameObject(this);
	}
}
