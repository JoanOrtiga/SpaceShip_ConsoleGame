#include "Player.h"

#include "LamterEngine/Console/ConsoleController.h"

Player::Player()
{
}

void Player::Update(double dt)
{
}

void Player::DrawnUpdate()
{
}

void Player::Draw()
{
	Lamter::ConsoleController::DrawAt(shape, position);
}
