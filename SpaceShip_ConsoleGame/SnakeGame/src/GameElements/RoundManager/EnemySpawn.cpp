#include "EnemySpawn.h"

#include "EnemySpawner.h"

EnemySpawn::EnemySpawn(int _enemyType, int _spawnPositionY, float _spawnDelay, int _quantity): spawnDelay(_spawnDelay),
	enemySpawnTimer(new Lamter::Timer(_spawnDelay, true, true, true, _spawnDelay)),
	enemyType(_enemyType), spawnPositionY(_spawnPositionY), quantity(_quantity)
{
}

EnemySpawn::~EnemySpawn()
{
	delete enemySpawnTimer;
}

void EnemySpawn::Tick(float dt)
{
	enemySpawnTimer->Tick(dt);

	if(enemySpawnTimer->IsReady())
	{
		EnemySpawner::SpawnEnemy(enemyType, spawnPositionY);
		currentQuantitySpawned++;
	}
}

bool EnemySpawn::SpawnedAll()
{
	return currentQuantitySpawned >= quantity;
}

void EnemySpawn::Reset()
{
	currentQuantitySpawned = 0;
}
