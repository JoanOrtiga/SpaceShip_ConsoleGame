#pragma once

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
	void DestroyGameObject(Lamter::GameObject* gameObject) override;
	void AddGameObject(Lamter::GameObject* _gameObject) override;
	void CollisionCheck() override;
	void EndGame() override;
};

