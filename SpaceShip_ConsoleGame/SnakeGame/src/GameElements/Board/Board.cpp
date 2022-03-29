#include "Board.h"

#include "LamterEngine/Console/ConsoleController.h"

Board::Board(Lamter::Game* _game): GameObject(_game)
{
	tag = "Board";
	position.x = -1;
	position.y = -1;
	orderInLayer = 10;
}

Board::~Board()
= default;

void Board::Awake()
{
	highscorePosition = { short(Lamter::ConsoleController::GetConsoleBufferSize().x - highscoreText.length() - 8), scoreSize };
	NewGame();
	UpdateHighScore(0);
	UpdateScore(0);
}

void Board::NewGame()
{
	DrawBoard();
}

void Board::Update(double dt)
{

}

void Board::DrawnUpdate()
{
}

void Board::Draw()
{
}


void Board::UpdateScore(int score)
{
	Lamter::ConsoleController::DrawAt(std::to_string(score), scorePosition.x + scoreText.length(), scorePosition.y);
}

void Board::UpdateHighScore(int score)
{
	Lamter::ConsoleController::DrawAt(std::to_string(score), highscorePosition.x + highscoreText.length(), highscorePosition.y);
}

void Board::DrawBoard()
{
	Lamter::ConsoleController::DrawAt(cornerTopLeft, 0, 0);
	Lamter::ConsoleController::Fill(flatHorizontal, Lamter::ConsoleController::GetConsoleBufferSize().x - 1);
	Lamter::ConsoleController::Draw(cornerTopRight);

	for (short i = 1; i < scoreSize + 1; ++i)
	{
		Lamter::ConsoleController::Draw(flatVertical);
		Lamter::ConsoleController::DrawAt(flatVertical, Lamter::ConsoleController::GetConsoleBufferSize().x - 1, i);
	}

	Lamter::ConsoleController::Draw(verticalWithRight);
	Lamter::ConsoleController::Fill(flatHorizontal, Lamter::ConsoleController::GetConsoleBufferSize().x - 1);
	Lamter::ConsoleController::Draw(verticalWithLeft);

	for (short i = 2 + scoreSize; i < Lamter::ConsoleController::GetConsoleBufferSize().y - 1; ++i)
	{
		Lamter::ConsoleController::Draw(flatVertical);
		Lamter::ConsoleController::DrawAt(flatVertical, Lamter::ConsoleController::GetConsoleBufferSize().x - 1, i);
	}

	Lamter::ConsoleController::Draw(cornerBottomLeft);
	Lamter::ConsoleController::Fill(flatHorizontal, Lamter::ConsoleController::GetConsoleBufferSize().x - 1);
	Lamter::ConsoleController::Draw(cornerBottomRight);

	Lamter::ConsoleController::DrawAt(scoreText, scorePosition);
	Lamter::ConsoleController::DrawAt(highscoreText, highscorePosition);
}

void Board::OnCollision(GameObject& other)
{
}

bool Board::IsColliding(GameObject& me, GameObject& other, Collider* otherCollider)
{
	bool x = other.position.x < 1 || other.position.x >= Lamter::ConsoleController::GetConsoleBufferSize().x-1;
	bool y = other.position.y <= 1 + scoreSize || other.position.y >= Lamter::ConsoleController::GetConsoleBufferSize().y - 1;

	if (x || y)
	{
		OnCollision(other);
		Collider::RaiseOnCollisionEvent(otherCollider, me);
		return true;
	}

	return false;
}
