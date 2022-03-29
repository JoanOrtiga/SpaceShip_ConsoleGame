#pragma once
#include <vector>


#include "EnemyGroup.h"

class Round
{
	float roundTime;
	std::vector<EnemyGroup*>* enemyGroups;

public:
	Round(float _roundTime);
	~Round();
	float GetRoundTime() const;
	void Tick(float dt);
	void AddEnemyGroup(EnemyGroup* enemyGroup);
	void ResetAll();
	float GetRoundTime()
	{
		return roundTime;
	}
};

