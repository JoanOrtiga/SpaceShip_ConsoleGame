#include "Round.h"

Round::Round(float _roundTime) : roundTime(_roundTime), enemyGroups(new std::vector<EnemyGroup*>())
{
	
}

Round::~Round()
{
}

float Round::GetRoundTime() const
{
	return roundTime;
}

void Round::Tick(float dt)
{
	for (auto enemyGroup : *enemyGroups)
	{
		if (enemyGroup->SpawnedAll())
			continue;

		enemyGroup->Tick(dt);
	}
}

void Round::AddEnemyGroup(EnemyGroup* enemyGroup)
{
	enemyGroups->push_back(enemyGroup);
}

void Round::ResetAll()
{
	for (auto element : *enemyGroups)
	{
		element->ResetAll();
	}
}
