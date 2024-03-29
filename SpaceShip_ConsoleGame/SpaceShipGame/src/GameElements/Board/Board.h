﻿#pragma once

#include "LamterEngine/Structures/Collider.h"
#include "LamterEngine/Structures/GameObject.h"

class Board : public Lamter::GameObject , public Lamter::Collider
{
public:
	static constexpr char BOARD_TAG[] = "Board";

private:
	const char cornerTopLeft = 201;		//╔
	const char cornerTopRight = 187;	//╗
	const char cornerBottomLeft = 200;	//╚
	const char cornerBottomRight = 188;	//╝

	const char flatVertical = 186;		//║
	const char flatHorizontal = 205;	//═

	const char verticalWithLeft = 185;	//╣
	const char verticalWithRight = 204;	//╠

	const short scoreSize = 1;
	const std::string scoreText = "Score: ";
	const std::string highscoreText = "Highscore: ";

	const Lamter::COORD scorePosition = { (short)5, scoreSize };
	Lamter::COORD highscorePosition;

	bool screenBug = false;
	
public:
	Board(Lamter::Game* _game);

	~Board() override;
	void Awake() override;
	void NewGame() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
	void UpdateScore(int score);
	void UpdateHighScore(int score);
	void DrawBoard();
	void OnCollision(GameObject& other) override;
	bool IsColliding(GameObject& me, GameObject& other, Collider* otherCollider) override;
};

