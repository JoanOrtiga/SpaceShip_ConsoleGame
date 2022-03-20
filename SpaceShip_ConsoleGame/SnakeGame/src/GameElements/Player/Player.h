#pragma once

#include "LamterEngine/Structures/GameObject.h"
#include "LamterEngine/Timers/Timer.h"

class Player : public Lamter::GameObject
{
private:
	const char shape = 62; //'>'

	Lamter::COORD moveDirection;
	Lamter::COORD lastPosition;
	Lamter::Timer* timer;
	float movementSpeed = 0.08; //TimeXCell

public:
	Player(Lamter::Game* _game);
	~Player() override;
	void Awake() override;
	void NewGame() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
};

