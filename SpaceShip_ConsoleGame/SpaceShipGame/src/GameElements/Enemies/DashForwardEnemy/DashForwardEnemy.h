#pragma once

#include "../EnemyShip.h"

class DashForwardEnemy : public EnemyShip
{
private:
	bool steppingForward = true;
	short stepsBack = 1;
	short stepsForward = 4;


public:
	DashForwardEnemy(short spawnHeight, Lamter::Game* _game);
	~DashForwardEnemy() override;
	void Move() override;
	bool IsColliding(GameObject& me, GameObject& other, Collider* otherCollider) override;
	void Awake() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
	void NewGame() override;
	void OnCollision(GameObject& other) override;
};


