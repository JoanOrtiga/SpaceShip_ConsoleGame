#pragma once

#include "../Enemies/ZigZag/ZigZagEnemy.h"
#include "../Enemies/DashForwardEnemy/DashForwardEnemy.h"

class EnemySpawner
{
public:
	static Lamter::Game* game;

	static void SpawnEnemy(short _enemyType, short _spawnPositionY)
	{
		switch (_enemyType)
		{
		case 0:
			new ZigZagEnemy(_spawnPositionY, game);
			break;
		case 1:
			new DashForwardEnemy(_spawnPositionY, game);
			break;
		}
	}
};