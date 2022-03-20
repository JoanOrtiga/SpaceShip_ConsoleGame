#include "LamterEngine/Engine/Engine.h"

#include "Game/SpaceshipGame.h"
#include "Game/SpaceshipMenu.h"


#define TARGET_FPS 30

int main()
{
	SpaceshipGame* spaceshipGame = new SpaceshipGame();
	SpaceshipMenu* spaceshipMenu = new SpaceshipMenu(spaceshipGame);
	Lamter::Engine engine(spaceshipMenu, spaceshipGame, TARGET_FPS, {70, 30},false);
    engine.Run();
}