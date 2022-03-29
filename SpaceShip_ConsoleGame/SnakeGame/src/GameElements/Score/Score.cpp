#include "Score.h"

#include "LamterEngine/Structures/GameExtensions.h"

Score::Score(Lamter::Game* _game) : GameObject(_game), currentScore(0), highScore(0)
{
	tag = "Score";
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
		board->UpdateHighScore(highScore);
	}
}

void Score::AddScore(int score)
{
	currentScore += score;
	board->UpdateScore(currentScore);
}

void Score::Awake()
{
	game->LoadGameObject(this, "Score.txt");
	board = Lamter::GameExtensions::GetGameObjectOfTypeByTag<Board>(game, "Board");
	board->UpdateScore(currentScore);
	board->UpdateHighScore(highScore);

}

void Score::NewGame()
{
}

void Score::Update(double dt)
{
}

void Score::DrawnUpdate()
{	
}

void Score::Draw()
{
}


void Score::SaveToFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* rootNode)
{
	tinyxml2::XMLElement* scoreElement = doc->NewElement("Score");
	//scoreElement->SetAttribute(GET_VARIABLE_NAME(highScore), highScore);
	auto highScoreElement = doc->NewElement(GET_VARIABLE_NAME(highScore));
	highScoreElement->SetText(highScore);
	scoreElement->InsertEndChild(highScoreElement);
	rootNode->InsertEndChild(scoreElement);
}

void Score::LoadFromFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* rootNode)
{
	tinyxml2::XMLElement* scoreElement = rootNode->FirstChildElement("Score");
	tinyxml2::XMLElement* highScoreElement = scoreElement->FirstChildElement(GET_VARIABLE_NAME(highScore));

	if (highScoreElement->QueryIntText(&highScore) != tinyxml2::XML_SUCCESS)
	{
		highScore = 0;
	}

	SetHighScore();
}
