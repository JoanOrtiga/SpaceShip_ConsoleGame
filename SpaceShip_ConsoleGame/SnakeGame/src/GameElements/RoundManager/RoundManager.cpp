#include "RoundManager.h"

#include "Round.h"
#include "LamterEngine/Console/ConsoleController.h"
#include "LamterEngine/Structures/Game.h"

RoundManager::RoundManager(Lamter::Game* _game) : GameObject(_game),
	roundTime(new Lamter::Timer(1, false, true, true, 1)), rounds(new std::vector<Round*>())
{
	tag = "RoundManager";
}

RoundManager::~RoundManager()
{
	delete rounds;
}

void RoundManager::Awake()
{
	game->LoadGameObject(this, "EnemyWaves.txt");
}

void RoundManager::NewGame()
{
	for (auto element : *rounds)
	{
		element->ResetAll();
	}
}

void RoundManager::Update(double dt)
{
	roundTime->Tick(dt);
	(*rounds)[currentRound]->Tick(dt);

	if(roundTime->IsReady())
	{
		currentRound++;
		if (currentRound >= rounds->size())
		{
			game->DestroyGameObject(this);
			return;
		}
		maxRoundTime = (*rounds)[currentRound]->GetRoundTime();
		roundTime->ChangeMaxTime(maxRoundTime);
		roundTime->Reset();
	}
}

void RoundManager::DrawnUpdate()
{
}

void RoundManager::Draw()
{

}

void RoundManager::LoadFromFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLElement* rootNode)
{
	/*
	 * Example:
		<enemyWaves>
			<round roundTime = "10">
				<enemies startSpawningTime = 0>
					<enemy: enemyType=0, spawnPositionY=5, spawnDelay=0, quantity = 1>
				<enemies/>
			<round/>
		<enemyWaves/>
	 *
	*/


	//<enemyWaves>
	auto enemyWavesNode = rootNode->FirstChildElement("enemyWaves");
	for (tinyxml2::XMLElement* roundElement = enemyWavesNode->FirstChildElement(); roundElement; roundElement = roundElement->NextSiblingElement())
	{
		//<round roundTime = 10>
		float roundTime = 0;
		roundElement->QueryFloatAttribute("roundTime", &roundTime);
		Round* newRound = new Round(roundTime);
		rounds->push_back(newRound);

		for (tinyxml2::XMLElement* enemyGroupElement = roundElement->FirstChildElement(); enemyGroupElement; enemyGroupElement = enemyGroupElement->NextSiblingElement())
		{
			//<enemies startSpawningTime = 0>
			float startSpawningTime = 0;
			enemyGroupElement->QueryFloatAttribute("startSpawningTime", & startSpawningTime);
			EnemyGroup* newEnemyGroup = new EnemyGroup(startSpawningTime);

			for (tinyxml2::XMLElement* enemyElement = enemyGroupElement->FirstChildElement(); enemyElement; enemyElement = enemyElement->NextSiblingElement())
			{
				//<enemy: type=0, yPosition=5, spawnTime=0, quantity = 1>
				int enemyType = 0;
				enemyElement->QueryIntAttribute("enemyType", &enemyType);
				int spawnPositionY = 0;
				enemyElement->QueryIntAttribute("spawnPositionY", &spawnPositionY);
				float spawnDelay = 0;
				enemyElement->QueryFloatAttribute("spawnDelay", &spawnDelay);
				int quantity = 0;
				enemyElement->QueryIntAttribute("quantity", &quantity);

				newEnemyGroup->AddEnemy(enemyType, spawnPositionY, spawnDelay, quantity);
			}

			newRound->AddEnemyGroup(newEnemyGroup);
		}
	}

	roundTime->ChangeMaxTime((*rounds)[currentRound]->GetRoundTime());
	roundTime->Reset(); 
}

