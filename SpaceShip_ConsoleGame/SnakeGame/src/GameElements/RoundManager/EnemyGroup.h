#pragma once
#include <vector>

#include "EnemySpawn.h"

class EnemyGroup
{
	float startSpawningTime;
	std::vector<EnemySpawn*>* enemySpawns;

public:
	EnemyGroup(float _startSpawningTime);
	~EnemyGroup();
	void Tick(float dt);
	void AddEnemy(int _enemyType, int _spawnPositionY, float _spawnDelay, int _quantity);
	void ResetAll();
	bool SpawnedAll();
};
