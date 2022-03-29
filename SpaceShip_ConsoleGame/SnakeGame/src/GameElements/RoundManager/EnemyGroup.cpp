#include "EnemyGroup.h"

EnemyGroup::EnemyGroup(float _startSpawningTime) : startSpawningTime(_startSpawningTime),
	enemySpawns(new std::vector<EnemySpawn*>())
{
}

EnemyGroup::~EnemyGroup()
{
	for (auto element : *enemySpawns)
	{
		delete element;
	}
	delete[] enemySpawns;
}

void EnemyGroup::Tick(float dt)
{
	for (auto enemySpawn : *enemySpawns)
	{
		enemySpawn->Tick(dt);
	}
}

void EnemyGroup::AddEnemy(int _enemyType, int _spawnPositionY, float _spawnDelay, int _quantity)
{
	enemySpawns->push_back(new EnemySpawn(_enemyType, _spawnPositionY, _spawnDelay, _quantity));
}

void EnemyGroup::ResetAll()
{
	for (auto element : *enemySpawns)
	{
		element->Reset();
	}
}

bool EnemyGroup::SpawnedAll()
{
	for (auto element : *enemySpawns)
	{
		if(!element->SpawnedAll())
		{
			return false;
		}
	}
	return true;
}
