#include "DashForwardEnemy.h"

#include "LamterEngine/Engine/Random.h"
#include "LamterEngine/Structures/Game.h"

DashForwardEnemy::DashForwardEnemy(short spawnHeight, Lamter::Game* _game) : EnemyShip(spawnHeight, _game)
{
	shape = '{';
}

DashForwardEnemy::~DashForwardEnemy()
{
}

void DashForwardEnemy::Move()
{
	lastPosition = position;
	position.x += steppingForward ? -stepsForward : stepsBack;
	steppingForward = !steppingForward;
}

void DashForwardEnemy::Awake()
{
	EnemyShip::Awake();
}

void DashForwardEnemy::Update(double dt)
{
	EnemyShip::Update(dt);
}

void DashForwardEnemy::DrawnUpdate()
{
	EnemyShip::DrawnUpdate();

	if (position.x <= stepsForward)
	{
		game->DestroyGameObject(this);
	}
}

void DashForwardEnemy::Draw()
{
	EnemyShip::Draw();
}

void DashForwardEnemy::NewGame()
{
	EnemyShip::NewGame();
}

void DashForwardEnemy::OnCollision(GameObject& other)
{
	if (other.tag == "Board")
	{
		position = lastPosition + Lamter::COORD(-1, 0);
	}
	EnemyShip::OnCollision(other);
}

bool DashForwardEnemy::IsColliding(GameObject& me, GameObject& other, Collider* otherCollider)
{
	return EnemyShip::IsColliding(me, other, otherCollider);
}
