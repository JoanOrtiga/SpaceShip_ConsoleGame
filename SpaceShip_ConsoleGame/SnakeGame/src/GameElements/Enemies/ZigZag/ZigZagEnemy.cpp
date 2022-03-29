#include "ZigZagEnemy.h"

#include "LamterEngine/Engine/Random.h"

ZigZagEnemy::ZigZagEnemy(short spawnHeight, Lamter::Game* _game): EnemyShip(spawnHeight, _game), zigZagCounter(zigZags)
{
	shape = goingUpChar;
}

ZigZagEnemy::~ZigZagEnemy() = default;

void ZigZagEnemy::Move()
{
	lastPosition = position;
	position += {-1, directionUp ? -1 : 1};

	zigZagCounter--;
	if(zigZagCounter <= 0)
	{
		shape = !directionUp ? goingUpChar : goingDownChar;
		directionUp = !directionUp;
		zigZagCounter = zigZags;
	}
}

void ZigZagEnemy::Awake()
{
	EnemyShip::Awake();
}

void ZigZagEnemy::Update(double dt)
{
	EnemyShip::Update(dt);
}

void ZigZagEnemy::DrawnUpdate()
{
	EnemyShip::DrawnUpdate();
}

void ZigZagEnemy::Draw()
{
	EnemyShip::Draw();
}

void ZigZagEnemy::NewGame()
{
	EnemyShip::NewGame();
}

void ZigZagEnemy::OnCollision(GameObject& other)
{
	if(other.tag == "Board")
	{
		position = lastPosition + Lamter::COORD( -1, 0 );
	}
	EnemyShip::OnCollision(other);
}

bool ZigZagEnemy::IsColliding(GameObject& me, GameObject& other, Collider* otherCollider)
{
	return EnemyShip::IsColliding(me, other, otherCollider);
}
