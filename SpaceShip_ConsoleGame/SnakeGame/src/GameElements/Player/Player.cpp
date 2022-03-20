#include "Player.h"

#include "LamterEngine/Console/ConsoleController.h"
#include "LamterEngine/Input/InputManager.h"

Player::Player(Lamter::Game* _game) : GameObject(_game)
{
}

Player::~Player()
{
	delete timer;
}

void Player::Awake()
{
	timer = new Lamter::Timer(movementSpeed, true, false, true, movementSpeed);
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

	timer->Tick(dt);
}

void Player::DrawnUpdate()
{
	if (!timer->IsReady())
		return;
	lastPosition = position;
	position += moveDirection;
	moveDirection = { 0,0 };
}

void Player::Draw()
{
	if (!timer->IsReady())
		return;
	if (lastPosition == position)
		return;

	Lamter::ConsoleController::DrawAt(shape, position);
	Lamter::ConsoleController::DeleteAt(lastPosition);
	timer->Consume();
}
