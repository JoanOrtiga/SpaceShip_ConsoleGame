#pragma once

#include <vector>

#include "LamterEngine/Structures/GameObject.h"
#include "LamterEngine/Structures/Game.h"

class SpaceshipGame : public Lamter::Game
{
public:

public:
	SpaceshipGame();
	~SpaceshipGame() override;
	void Init() override;
	void NewGame() override;
	bool ExitLoop() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
};

