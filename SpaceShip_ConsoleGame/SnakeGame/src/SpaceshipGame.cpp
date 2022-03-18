#include "SpaceshipGame.h"

SpaceshipGame::SpaceshipGame() = default;

SpaceshipGame::~SpaceshipGame() = default;

void SpaceshipGame::Init()
{
	Game::Init();
}

void SpaceshipGame::NewGame()
{
}

bool SpaceshipGame::ExitLoop()
{
	return Game::ExitLoop();
}

void SpaceshipGame::Update(double dt)
{
	Game::Update(dt);
}

void SpaceshipGame::DrawnUpdate()
{
	Game::DrawnUpdate();
}

void SpaceshipGame::Draw()
{
	Game::Draw();
}

void SpaceshipGame::DestroyGameObject(Lamter::GameObject* gameObject)
{
	Game::DestroyGameObject(gameObject);
}
