#pragma once

#include "LamterEngine/Structures/Collider.h"
#include "LamterEngine/Structures/GameObject.h"
#include "LamterEngine/Timers/Timer.h"

class Bullet : public Lamter::GameObject, public Lamter::Collider
{
private:
	const char bulletChar = '-';
	const Lamter::COORD moveDirection = {1, 0};

	Lamter::Timer* timer;
	float movementSpeed = 0.02; //TimeXCell

public:
	Bullet(Lamter::Game* _game, Lamter::COORD _position);
	~Bullet() override;

	void Awake() override;
	void NewGame() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
	void OnCollision(GameObject& other) override;
	bool IsColliding(GameObject& me, GameObject& other, Collider* otherCollider) override;
};

