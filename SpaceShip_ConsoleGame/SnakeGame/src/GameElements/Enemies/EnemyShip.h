#pragma once

#include "LamterEngine/Console/ConsoleController.h"
#include "LamterEngine/Structures/Collider.h"
#include "LamterEngine/Structures/GameObject.h"
#include "LamterEngine/Timers/Timer.h"

class EnemyShip : public Lamter::GameObject , public Lamter::Collider
{
protected:
	Lamter::Timer* movingTimer;
	float movementSpeed = 0.76;
	Lamter::COORD lastPosition;
	char shape = '%';
	int scorePoints = 10;

public:
	EnemyShip(short spawnHeight, Lamter::Game* _game);
	~EnemyShip() override;
	void Awake() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
	void NewGame() override;
	void OnCollision(GameObject& other) override;

	virtual void Move() = 0;
private:
	
};

