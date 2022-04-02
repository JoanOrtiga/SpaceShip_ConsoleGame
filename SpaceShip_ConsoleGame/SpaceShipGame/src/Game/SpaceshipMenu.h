#pragma once

#include "LamterEngine/Structures/Menu.h"
#include "LamterEngine/Structures/Game.h"


class SpaceshipMenu : public Lamter::Menu
{
public:
	SpaceshipMenu(Lamter::Game* _game);
	~SpaceshipMenu() override;
	void Update() override;
	void Draw() override;
	void InitialDraw() override;
};

