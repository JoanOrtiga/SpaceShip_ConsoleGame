#include "Bullet.h"

#include <sstream>

#include "LamterEngine/Console/ConsoleController.h"
#include "LamterEngine/Structures/Game.h"

Bullet::Bullet(Lamter::Game* _game, Lamter::COORD _position): GameObject(_game)
{
	tag = "Bullet";
	position = _position;
	timer = new Lamter::Timer(movementSpeed, false, false, true, movementSpeed);
}

Bullet::~Bullet()
{
	delete timer;
}

void Bullet::Awake()
{
}

void Bullet::NewGame()
{
}

void Bullet::Update(double dt)
{
	timer->Tick(dt);
}

void Bullet::DrawnUpdate()
{
	if (!timer->IsReady())
		return;
	position += moveDirection;
}

void Bullet::Draw()
{
	if (!timer->IsReady())
		return;
	Lamter::ConsoleController::DeleteAt(position - moveDirection);
	Lamter::ConsoleController::DrawAt(bulletChar, position);
	timer->Consume();
}

void Bullet::OnCollision(GameObject& other)
{
	if(other.tag == "Board" || other.tag == "Enemy")
	{
		Lamter::ConsoleController::DeleteAt(position - moveDirection);
		game->DestroyGameObject(this);
		timer->Stop();
		timer->Consume();
	}
}

bool Bullet::IsColliding(GameObject& me, GameObject& other, Collider* otherCollider)
{
	return Collider::IsColliding(me, other, otherCollider);
}

