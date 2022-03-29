#include "Explosion.h"

#include "LamterEngine/Console/ConsoleController.h"
#include "LamterEngine/Structures/Game.h"
#include "../Board/Board.h"
#include "LamterEngine/Structures/GameExtensions.h"

Explosion::Explosion(Lamter::COORD spawnPosition, Lamter::Game* _game) : GameObject(_game)
{
	position = spawnPosition;
	movingTimer = new Lamter::Timer(movementSpeed, false, false, true, movementSpeed);
}

Explosion::~Explosion()
{
	delete movingTimer;
};

void Explosion::Awake()
{
	
}

void Explosion::NewGame()
{
}

void Explosion::Update(double dt)
{
	movingTimer->Tick(dt);
	
	if (currentState >= maxStates - 1)
	{
		game->DestroyGameObject(this);
	}
}

void Explosion::DrawnUpdate()
{
	if (!movingTimer->IsReady())
		return;

	currentState++;
}

void Explosion::Draw()
{
	if (!movingTimer->IsReady())
		return;
	movingTimer->Consume();

	for (short i = -(explosionSizeY / 2); i < explosionSizeY-1; ++i)
	{
		std::string explosionLine;
		for (short j = -(explosionSizeX / 2); j < explosionSizeX - 1; ++j)
		{
			explosionLine += explosionShape[currentState][j + (explosionSizeX / 2)][i + (explosionSizeY / 2)];
		}
		Lamter::ConsoleController::DrawAt(explosionLine, position.x-1, position.y-i);
	}

	Lamter::GameExtensions::GetGameObjectOfTypeByTag<Board>(game, "Board")->DrawBoard();
}


