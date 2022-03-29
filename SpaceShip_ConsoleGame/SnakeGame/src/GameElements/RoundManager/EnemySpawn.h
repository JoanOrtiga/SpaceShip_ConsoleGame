#pragma once

#include "LamterEngine/Timers/Timer.h"

class EnemySpawn
{
private:
	Lamter::Timer* enemySpawnTimer;
	int enemyType;
	int spawnPositionY;
	float spawnDelay;
	int quantity;

	int currentQuantitySpawned = 0;

public:
	EnemySpawn(int _enemyType, int _spawnPositionY, float _spawnDelay, int _quantity);
	~EnemySpawn();
	void Tick(float dt);
	bool SpawnedAll();
	void Reset();
};

