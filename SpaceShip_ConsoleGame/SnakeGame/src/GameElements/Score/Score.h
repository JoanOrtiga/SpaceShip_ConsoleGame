#pragma once

#include "LamterEngine/Structures/Object.h"

class Score : Object
{
private:
	int currentScore;
	int highScore;

public:
	Score();
	int GetCurrentScore();
	int GetHighScore();
	void SetHighScore();
};

