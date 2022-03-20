#pragma once

#include "LamterEngine/Structures/GameObject.h"

class Bullet : public Lamter::GameObject
{
public:
	Bullet(Lamter::Game* _game);
	~Bullet() override;

	void Awake() override;
	void NewGame() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
	
};

