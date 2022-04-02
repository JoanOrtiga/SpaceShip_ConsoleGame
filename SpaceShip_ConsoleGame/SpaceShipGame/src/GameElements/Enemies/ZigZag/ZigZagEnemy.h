#pragma once

#include "../EnemyShip.h"

class ZigZagEnemy : public EnemyShip 
{
private:
	bool directionUp = true;
	short zigZags = 2;
	short zigZagCounter;
	const char goingUpChar = '^';
	const char goingDownChar = 'v';


public:
	ZigZagEnemy(short spawnHeight, Lamter::Game* _game);
	~ZigZagEnemy() override;
	void Move() override;
	bool IsColliding(GameObject& me, GameObject& other, Collider* otherCollider) override;
	void Awake() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
	void NewGame() override;
	void OnCollision(GameObject& other) override;
};

