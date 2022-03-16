#include "Score.h"

Score::Score() : currentScore(0), highScore(0)
{
}

int Score::GetCurrentScore()
{
	return currentScore;
}

int Score::GetHighScore()
{
	return highScore;
}

/**
 * \brief Sets currentScore as highScore if (currentscore > highScore)
 */
void Score::SetHighScore()
{
	if(currentScore > highScore)
	{
		highScore = currentScore;
	}
}
