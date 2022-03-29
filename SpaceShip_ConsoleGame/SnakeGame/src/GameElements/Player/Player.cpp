#include "Player.h"

#include <sstream>

#include "Bullet.h"
#include "LamterEngine/Console/ConsoleController.h"
#include "LamterEngine/Input/InputManager.h"
#include "LamterEngine/Structures/Game.h"

Player::Player(Lamter::Game* _game) : GameObject(_game)
{
	tag = "Player";
}

Player::~Player()
{
	delete movingTimer;
}

void Player::Awake()
{
	shootingTimer = new Lamter::Timer(timeBetweenShots, true, true, true, timeBetweenShots);
	movingTimer = new Lamter::Timer(movementSpeed, true, false, true, movementSpeed);
	position = { 3, Lamter::ConsoleController::GetConsoleBufferSize().y / 2 + 3 };
	Draw();
	lastPosition = position;
}

void Player::NewGame()
{
}

void Player::Update(double dt)
{
	if(Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::W))
	{
		moveDirection.y = -1;
	}
	else if (Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::S))
	{
		moveDirection.y = 1;
	}
	else
	{
		moveDirection.y = 0;
	}

	if (Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::D))
	{
		moveDirection.x = 1;
	}
	else if (Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::A))
	{
		moveDirection.x = -1;
	}
	else
	{
		moveDirection.x = 0;
	}

	if (Lamter::InputManager::IsKeyPressed(Lamter::KeyCode::SpaceBar))
		wantsToShoot = true;
	else 
		wantsToShoot = false;

	shootingTimer->Tick(dt);
	movingTimer->Tick(dt);
}

void Player::DrawnUpdate()
{
	if (wantsToShoot && shootingTimer->IsReady())
	{
		auto bullet = new Bullet(game, { short(position.x + 1), position.y });
	}

	if (!movingTimer->IsReady())
		return;

	lastPosition = position;
	position += moveDirection;
	moveDirection = { 0,0 };
}

void Player::Draw()
{
	if (!movingTimer->IsReady())
		return;
	if (lastPosition == position)
		return;

	Lamter::ConsoleController::DrawAt(shape, position);
	Lamter::ConsoleController::DeleteAt(lastPosition);
	movingTimer->Consume();
}

void Player::OnCollision(GameObject& other)
{
	if(other.tag == "Board")
	{
		position = lastPosition;
	}
	else if(other.tag == "Enemy")
	{
		game->EndGame();
	}
}
