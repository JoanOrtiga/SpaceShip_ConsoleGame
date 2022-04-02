#pragma once

#include "LamterEngine/Structures/GameObject.h"
#include "../Board/Board.h"

class Score : Lamter::GameObject
{
private:
	int currentScore;
	int highScore;
	Board* board;

public:
	Score(Lamter::Game* _game);
	int GetCurrentScore();
	int GetHighScore();
	void SetHighScore();
	void AddScore(int score);

	void Awake() override;
	void NewGame() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;

	void SaveToFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLElement* rootNode) override;
	void LoadFromFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLElement* rootNode) override;
};

