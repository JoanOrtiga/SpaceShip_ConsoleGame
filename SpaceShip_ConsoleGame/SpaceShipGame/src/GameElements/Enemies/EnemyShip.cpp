#include "EnemyShip.h"

#include "LamterEngine/Structures/Game.h"
#include "../Explosion/Explosion.h"
#include "LamterEngine/Structures/GameExtensions.h"

#include "../Score/Score.h"

EnemyShip::EnemyShip(short spawnHeight, Lamter::Game* _game) : GameObject(_game)
{
	position.y = spawnHeight;
	tag = "Enemy";
	movingTimer = new Lamter::Timer(movementSpeed, true, false, true, movementSpeed);
}

EnemyShip::~EnemyShip()
{
	Lamter::GameExtensions::GetGameObjectOfTypeByTag<Score>(game, "Score")->AddScore(scorePoints);
	;
	new Explosion(position, game);
	Lamter::ConsoleController::DeleteAt(position);
	Lamter::ConsoleController::DeleteAt(lastPosition);
	delete movingTimer;
}

void EnemyShip::Awake()
{
	position.x = Lamter::ConsoleController::GetConsoleBufferSize().x - 2;
}

void EnemyShip::Update(double dt)
{
	movingTimer->Tick(dt);
}

void EnemyShip::DrawnUpdate()
{
	if (!movingTimer->IsReady())
		return;

	Move();

	if(position.x <= 1)
	{
		game->DestroyGameObject(this);
	}
}

void EnemyShip::Draw()
{
	if (!movingTimer->IsReady())
		return;
	if (lastPosition == position)
		return;
	Lamter::ConsoleController::DrawAt(shape, position);
	Lamter::ConsoleController::DeleteAt(lastPosition);
	movingTimer->Consume();
}

void EnemyShip::NewGame()
{
}

void EnemyShip::OnCollision(GameObject& other)
{
	if(other.tag == "Player" || other.tag == "Bullet")
	{
		game->DestroyGameObject(this);
	}
}


