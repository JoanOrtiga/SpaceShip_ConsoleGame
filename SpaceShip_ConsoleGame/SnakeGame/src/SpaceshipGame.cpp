#include "SpaceshipGame.h"


SpaceshipGame::SpaceshipGame() : gameObjects(new std::vector<Lamter::GameObject>())
{
}

SpaceshipGame::~SpaceshipGame()
{
	delete[] gameObjects;
}

void SpaceshipGame::Init()
{
}

void SpaceshipGame::NewGame()
{
}

bool SpaceshipGame::ExitLoop()
{
}

void SpaceshipGame::Update(double dt)
{
	for (auto& gameObject : *gameObjects)
	{
		gameObject.Update(dt);
	}
}

void SpaceshipGame::DrawnUpdate()
{
	for (auto& gameObject : *gameObjects)
	{
		gameObject.DrawnUpdate();
	}
}

void SpaceshipGame::Draw()
{
	
}

void SpaceshipGame::DestroyActor(Lamter::GameObject* gameObject)
{
	
}
