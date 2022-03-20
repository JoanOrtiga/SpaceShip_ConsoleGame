#include "SpaceshipGame.h"

#include "../GameElements/Board/Board.h"
#include "../GameElements/Player/Player.h"

SpaceshipGame::SpaceshipGame() : Game()
{
	auto board = new Board(this);
	auto player = new Player(this);
}

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

void SpaceshipGame::AddGameObject(Lamter::GameObject* _gameObject)
{
	Game::AddGameObject(_gameObject);
}

void SpaceshipGame::DestroyGameObject(Lamter::GameObject* gameObject)
{
	Game::DestroyGameObject(gameObject);
}

void SpaceshipGame::CollisionCheck()
{
	Game::CollisionCheck();
}

