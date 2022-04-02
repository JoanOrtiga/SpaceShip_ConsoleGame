#pragma once

#include <vector>

#include "LamterEngine/Structures/GameObject.h"
#include "LamterEngine/XMLParser/ILoadable.h"

#include "LamterEngine/Timers/Timer.h"

#include "Round.h"

class RoundManager : public Lamter::GameObject
{
private:
	Lamter::Timer* roundTime;
	std::vector<Round*>* rounds;
	int currentRound = 0;
	float maxRoundTime = 0;

public:
	RoundManager(Lamter::Game* _game);
	~RoundManager() override;
	void Awake() override;
	void NewGame() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
	void LoadFromFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLElement* rootNode) override;
};

