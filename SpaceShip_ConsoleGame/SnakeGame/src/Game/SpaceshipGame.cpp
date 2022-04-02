#include "SpaceshipGame.h"

#include "../GameElements/Board/Board.h"
#include "../GameElements/Player/Player.h"
#include "../GameElements/Enemies/ZigZag/ZigZagEnemy.h"
#include "../GameElements/Enemies/DashForwardEnemy/DashForwardEnemy.h"
#include "LamterEngine/Structures/GameExtensions.h"
#include "../GameElements/Score/Score.h"
#include "../GameElements/RoundManager/RoundManager.h"
#include "../GameElements/RoundManager/EnemySpawner.h"

SpaceshipGame::SpaceshipGame() : Game()
{
	new Board(this);
	new Player(this);
	new Score(this);
	new RoundManager(this);

	EnemySpawner::game = this;
}

SpaceshipGame::~SpaceshipGame() = default;

void SpaceshipGame::Init()
{
	Game::Init();
}

void SpaceshipGame::NewGame()
{
	Game::NewGame();

	gameObjects->clear();
	destroyGameObjectsQueue->clear();
	addGameObjectsQueue->clear();

	new Board(this);
	new Player(this);
	new Score(this);
	new RoundManager(this);
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

void SpaceshipGame::EndGame()
{
	SaveGameObject(Lamter::GameExtensions::GetGameObjectOfTypeByTag(this, "Score"), "Score.txt");
	exitGame = true;
}

