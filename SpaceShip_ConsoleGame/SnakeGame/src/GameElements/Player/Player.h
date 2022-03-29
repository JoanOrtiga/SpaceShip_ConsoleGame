#pragma once

#include "LamterEngine/Structures/Collider.h"
#include "LamterEngine/Structures/GameObject.h"
#include "LamterEngine/Timers/Timer.h"

class Player : public Lamter::GameObject , public Lamter::Collider
{
private:
	const char shape = 62; //'>'

	Lamter::COORD moveDirection;
	Lamter::COORD lastPosition;
	Lamter::Timer* movingTimer;
	float movementSpeed = 0.07; //TimeXCell

	Lamter::Timer* shootingTimer;
	float timeBetweenShots = 0.2; //TimeXCell
	bool wantsToShoot = false;

public:
	Player(Lamter::Game* _game);
	~Player() override;
	void Awake() override;
	void NewGame() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
	void OnCollision(GameObject& other) override;
};

